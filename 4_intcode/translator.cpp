#include "translator.h"
#include <algorithm>
translator global_tab;
string tmpIdName;
map<string,int>type2size={
    {"INT",4},
    {"REAL",4}
};
string getTokenStr(int token)
{

    static const char *token_strs[] = {
    "Le", "Ge", "Eq", "Ne", "Def", "And", "Or", "IntConstant", "REAL", "RealConstant", "StringConstant", "Identifier", "INT", "WHILE",
    "If", "Else", "Return", "OP", "BEGIN_KEY", "END_KEY", "DECLARE", "MAIN", "WRITE", "READ"};
    return token_strs[token-256];
}

void yyerror(char *s) {
    fprintf(stderr, "line %d: %s\n", yylineno, s);
}

node* createNode(char *name, int lineno)
{
    auto root = new node();
    root->lineNo=lineno;
    root->name=name;
    /* 3 case of terminal:
    *   string
    *   int
    *   float
    */
    if (root->name=="Identifier" || root->name=="StringConstant")
    {
        root->idName = string(yytext);
    }
    else if (root->name=="IntConstant")
        root->intVal = atoi(yytext);
    else if (root->name=="RealConstant")
        root->floatVal = atof(yytext);
    return root;
}


symbol_table::symbol_table(shared_ptr<symbol_table> t) : prev(t) {}
bool symbol_table::enter(string lexeme, string type, int offset)
{
    if(_table.find(lexeme)!=_table.end()){
        yyerror("duplicated variable definition\n");
        return false;
    }
    // enter(top(tblptr),id.lexeme,T.type,top(offset));
    _table[lexeme]=entry{lexeme, type, false, offset, nullptr};
    return true;
}
bool symbol_table::enterproc(string lexeme, shared_ptr<symbol_table> fptr)
{
    if(_table.find(lexeme)!=_table.end()){
        yyerror("duplicated function definition\n");
        return false;
    }
    _table[lexeme]=entry{lexeme, "Identifier", true, 0, fptr};
    return true;
}
void symbol_table::addwidth(int width)
{
    _size = width;
}
int symbol_table::size()const{
    return _size;
}
const map<string,symbol_table::entry>&symbol_table::table()const{
    return _table;
}

ostream &operator<<(ostream &os, symbol_table *t)
{
    if(!t)return os;
    queue<pair<shared_ptr<symbol_table>,string>>symTabq;
    symTabq.push(make_pair(shared_ptr<symbol_table>(t),"main"));
    while(!symTabq.empty()){
        auto p=symTabq.front();
        auto table=p.first->table();
        symTabq.pop();
        os << "----------------------------------" <<endl
        << "<table>"<<left<<setw(13)<<p.second<<"|" << p.first->size() << endl
         << "----------------------------------" <<endl;
        auto vec=vector<pair<string, symbol_table::entry>>(table.begin(),table.end());
        sort(vec.begin(),vec.end(),[](pair<const std::string, symbol_table::entry>p1,pair<const std::string, symbol_table::entry>p2){return p1.second.addr<p2.second.addr;});
        for (const auto &ent : vec)
        {
            auto record=ent.second;
            if (record.isFunc){
                symTabq.push(make_pair(record.fptr,record.identifier));
                os <<left << setw(20) << record.identifier <<'|'<<left<<setw(8)<<"FUNC"<<'|' << endl;
            }
            else
                os <<left << setw(20) << record.identifier<<'|'<<left<<setw(8)<<record._type <<'|'<< record.addr << endl;
        }
        os << "----------------------------------" << endl<<endl;
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
