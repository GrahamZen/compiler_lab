#ifndef TRANSLATOR_H
#define TRANSLATOR_H
#include "token.h"
#include <iostream>
#include <iomanip>
#include <memory>
#include <stack>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

extern int yylineno;
extern char *yytext;
void yyerror(char *s);

class symbol_table
{
private:
    struct entry
    {
        string identifier;
        TokenType t;
        bool isFunc;
        int addr;
        shared_ptr<symbol_table> fptr;
    };
    vector<entry> _table;
    shared_ptr<symbol_table> prev = nullptr;
    int _size = 0;

public:
    symbol_table() = default;
    symbol_table(shared_ptr<symbol_table> t) : prev(t) {}
    ~symbol_table() = default;
    void enter(const char *lexeme, TokenType type, int offset)
    {
        // enter(top(tblptr),id.lexeme,T.type,top(offset));
        _table.push_back(entry{string(lexeme), type, false, offset, nullptr});
    }
    void enterproc(const char *lexeme, shared_ptr<symbol_table> fptr)
    {
        // enter(top(tblptr),id.lexeme,T.type,top(offset));
        _table.push_back(entry{string(lexeme), Identifier, true, 0, fptr});
    }
    void addwidth(int width)
    {
        _size = width;
    }
    int size()const{
        return _size;
    }
    const vector<entry>&table()const{
        return _table;
    }
    friend ostream &operator<<(ostream &os, symbol_table t);
};

ostream &operator<<(ostream &os, shared_ptr<symbol_table> t)
{
    if(!t)return os;
    queue<pair<shared_ptr<symbol_table>,string>>symTabq;
    symTabq.push(make_pair(t,"main"));
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

class translator
{
    // private:
public:
    translator() : t(new symbol_table()) {}
    ~translator() = default;
    void addwidth(int width)
    {
        offsetSt.top() += width;
    }
    shared_ptr<symbol_table> t = nullptr;
    stack<shared_ptr<symbol_table>> tblSt;
    stack<int> offsetSt;
};

#endif
