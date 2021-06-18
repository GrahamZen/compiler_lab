#include "translator.h"
#include <algorithm>
#include <cstring>
translator global_tab;
string tmpIdName;
int funcArgNum;
bool isTypeDef;
map<string, int> type2size = {
    {"INT", 4},
    {"REAL", 4}};

string getTokenStr(int token)
{
    static const char *token_strs[] = {
        "Le", "Ge", "Eq", "Ne", "Def", "And", "Or", "IntConstant", "REAL", "RealConstant", "StringConstant", "Identifier", "INT", "WHILE",
        "If", "Else", "Return", "OP", "BEGIN_KEY", "END_KEY", "DECLARE", "MAIN", "WRITE", "READ"};
    return token_strs[token - 256];
}
#ifdef YACC

void yyerror(char *s)
{
    fprintf(stderr, "line %d: %s\n", yylineno, s);
}

node *createNode(char *typeName, int lineno)
{
    auto root = new node();
    root->_lineNo = lineno;
    root->typeName = typeName;
    /* 3 case of terminal:
    *   string
    *   int
    *   float
    */
    if (root->typeName == "Identifier" || root->typeName == "StringConstant")
    {
        root->idName = string(yytext);
    }
    else if (root->typeName == "IntConstant")
        root->intVal = atoi(yytext);
    else if (root->typeName == "RealConstant")
        root->floatVal = atof(yytext);
    return root;
}
#endif // YACC

symbol_table::symbol_table(shared_ptr<symbol_table> t) : prev(t)
{
}
bool symbol_table::enter(string lexeme, string type, int offset)
{
    if (_table.find(lexeme) != _table.end())
    {
#ifdef YACC
        yyerror("Duplicated variable definition.\n");
#endif // YACC
        return false;
    }
    // enter(top(tblptr),id.lexeme,T.type,top(offset));
    _table[lexeme] = entry{lexeme, type, false,false, offset, nullptr};
    return true;
}
bool symbol_table::enterproc(string lexeme, shared_ptr<symbol_table> fptr,bool isMain)
{
    if (_table.find(lexeme) != _table.end())
    {
#ifdef YACC
        yyerror("Duplicated function definition.\n");
#endif // YACC
        return false;
    }
    _table[lexeme] = entry{lexeme, "Identifier", true,isMain, 0, fptr};
    return true;
}
void symbol_table::addwidth(int width)
{
    _size = width;
}

string symbol_table::newTemp()
{
    tmpCnt++;
    return "t" + to_string(tmpCnt);
}
string symbol_table::newLabel()
{
    labelCnt++;
    return "t" + to_string(labelCnt);
}

string symbol_table::lookup(string idName,bool errFlag)
{
    if (_table.find(idName) != _table.end())
        return idName;
    else if(errFlag)
    {
#ifdef YACC
        auto msg=string("Referenced non-existed variable ")+idName+".";
        char*str=new char[msg.size()];
        strcpy(str,msg.c_str());
        yyerror(str);
#endif // YACC
    }
    return string();
}

int symbol_table::size() const
{
    return _size;
}
const map<string, symbol_table::entry> &symbol_table::table() const
{
    return _table;
}

ostream &operator<<(ostream &os, shared_ptr<symbol_table> t)
{
    if (!t)
        return os;
    queue<pair<shared_ptr<symbol_table>, string>> symTabq;
    symTabq.push(make_pair(shared_ptr<symbol_table>(t), "main"));
    while (!symTabq.empty())
    {
        auto p = symTabq.front();
        auto table = p.first->table();
        symTabq.pop();
        os << "----------------------------------" << endl
           << "<table>" << left << setw(13) << p.second << "|" << p.first->size() << endl
           << "----------------------------------" << endl;
        auto vec = vector<pair<string, symbol_table::entry>>(table.begin(), table.end());
        sort(vec.begin(), vec.end(), [](pair<const std::string, symbol_table::entry> p1, pair<const std::string, symbol_table::entry> p2)
             { return p1.second.addr < p2.second.addr; });
        for (const auto &ent : vec)
        {
            auto record = ent.second;
            if (record.isFunc)
            {
                symTabq.push(make_pair(record.fptr, record.identifier));
                os << left << setw(20) << record.identifier+(record.isMain?"<main>":"") << '|' << left << setw(8) << "FUNC" << '|' << endl;
            }
            else
                os << left << setw(20) << record.identifier << '|' << left << setw(8) << record._type << '|' << record.addr << endl;
        }
        os << "----------------------------------" << endl
           << endl;
    }
    return os;
}

shared_ptr<symbol_table> mktable(shared_ptr<symbol_table> t)
{
    return make_shared<symbol_table>(t);
}

translator::translator() : t(new symbol_table()) {}

void translator::addwidth(int width)
{
    offsetSt.top() += width;
}

void intCodeGenerator::gen(string op, string result, string arg1, string arg2)
{
    ct.emplace_back(op, result, arg1, arg2);
}
void intCodeGenerator::gen(string label)
{
    ct.emplace_back(label);
}

string intCodeGenerator::Quad2Str(const codeQuad &c) const
{
    if (c.isLabel)
        return c._label + ':';
    if (string("+-*/").find(c._op) != string::npos)
        return '\t' + c._result + " = " + c._arg1 + ' ' + c._op + ' ' + c._arg2;
    if (c._op == "=")
        return '\t' + c._result + " = " + c._arg1;
    if (c._op == "call")
        return '\t' + c._result + " = " + c._op + ' ' + c._arg1 + ", " + c._arg2;
    if (c._op == "read" || c._op == "write")
        return "\tcall " + c._op +", "+ c._result;
    return '\t' + c._op + ' ' + c._result;
}

ostream &operator<<(ostream &os, const intCodeGenerator &t)
{
    for (const auto &c : t.ct)
    {
        os << t.Quad2Str(c) << endl;
    }
    return os;
}
