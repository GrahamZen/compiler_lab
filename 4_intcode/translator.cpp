#include "translator.h"

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

symbol_table::symbol_table(shared_ptr<symbol_table> t) : prev(t) {}
void symbol_table::enter(const char *lexeme, yytokentype type, int offset)
{
    // enter(top(tblptr),id.lexeme,T.type,top(offset));
    _table.push_back(entry{string(lexeme), type, false, offset, nullptr});
}
void symbol_table::enterproc(const char *lexeme, shared_ptr<symbol_table> fptr)
{
    // enter(top(tblptr),id.lexeme,T.type,top(offset));
    _table.push_back(entry{string(lexeme), Identifier, true, 0, fptr});
}
void symbol_table::addwidth(int width)
{
    _size = width;
}
int symbol_table::size()const{
    return _size;
}
const vector<symbol_table::entry>&symbol_table::table()const{
    return _table;
}

ostream &operator<<(ostream &os, symbol_table *t)
{
    if(!t)return os;
    queue<pair<shared_ptr<symbol_table>,string>>symTabq;
    symTabq.push(make_pair(shared_ptr<symbol_table>(t),"main"));
    while(!symTabq.empty()){
        auto p=symTabq.front();
        auto table=p.first;
        symTabq.pop();
        os << "----------------------------------" <<endl
        << "<table>"<<left<<setw(13)<<p.second<<"|" << table->size() << endl
         << "----------------------------------" <<endl;
        for (const auto &ent : table->table())
        {
            if (ent.isFunc){
                symTabq.push(make_pair(ent.fptr,ent.identifier));
                os <<left << setw(20) << ent.identifier <<'|'<<left<<setw(8)<<"FUNC"<<'|' << endl;
            }
            else
                os <<left << setw(20) << ent.identifier<<'|'<<left<<setw(8)<<getTokenStr(ent.t) <<'|'<< ent.addr << endl;
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
