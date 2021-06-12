#ifndef TRANSLATOR_H
#define TRANSLATOR_H
#include <iostream>
#include <iomanip>
#include <memory>
#include <stack>
#include <vector>
#include <queue>
#include "syn_tree.tab.h"
using namespace std;

extern int yylineno;
extern char *yytext;
class symbol_table
{
private:
    struct entry
    {
        string identifier;
        yytokentype t;
        bool isFunc;
        int addr;
        shared_ptr<symbol_table> fptr;
    };
    vector<entry> _table;
    shared_ptr<symbol_table> prev = nullptr;
    int _size = 0;

public:
    symbol_table() = default;
    symbol_table(shared_ptr<symbol_table> t);
    ~symbol_table() = default;
    void enter(const char *lexeme, yytokentype type, int offset);
    void enterproc(const char *lexeme, shared_ptr<symbol_table> fptr);
    void addwidth(int width);
    int size()const;
    const vector<entry>&table()const;
    friend ostream &operator<<(ostream &os, symbol_table *t);
};

shared_ptr<symbol_table> mktable(shared_ptr<symbol_table> t);
class translator
{
    // private:
public:
    translator();
    ~translator() = default;
    void addwidth(int width);
    shared_ptr<symbol_table> t = nullptr;
    stack<shared_ptr<symbol_table>> tblSt;
    stack<int> offsetSt;
};

#endif
