#ifndef TRANSLATOR_H
#define TRANSLATOR_H
#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <stack>
#include <string>
#include <vector>
// #include "syn_tree.tab.h"
using namespace std;

extern int yylineno;
extern char *yytext;

struct node
{
    int lineNo;
    string name; //type name
    string idName;
    int intVal = 0;
    float floatVal = 0;
};

node *createNode(char *name, int lineno);
class symbol_table
{
public:
    struct entry
    {
        string identifier;
        string _type;
        bool isFunc;
        int addr;
        shared_ptr<symbol_table> fptr;
    };
    symbol_table()
    {
        cout << "symbol_table created.\n";
    }
    symbol_table(shared_ptr<symbol_table> t);
    ~symbol_table() { cout << "symbol_table destroyed.\n"; };
    bool enter(string lexeme, string type, int offset);
    bool enterproc(string lexeme, shared_ptr<symbol_table> fptr);
    void addwidth(int width);
    int size() const;
    const map<string, symbol_table::entry> &table() const;
    friend ostream &operator<<(ostream &os, shared_ptr<symbol_table> t);

private:
    map<string, entry> _table;
    shared_ptr<symbol_table> prev = nullptr;
    int _size = 0;
};

shared_ptr<symbol_table> mktable(shared_ptr<symbol_table> t);

class intCodeGenerator
{
public:
    struct codeQuad
    {
        string _op, _arg1, _arg2, _result;
        int _label;
        bool isLabel;
        codeQuad(string op, string result, string arg1 = string(), string arg2 = string()) : _op(op), _result(result), isLabel(false)
        {
            if (!arg1.empty())
                _arg1 = arg1;
            if (!arg2.empty())
                _arg2 = arg2;
        }
        codeQuad(int label) : _label(label), isLabel(true) {}
    };
    intCodeGenerator() = default;
    ~intCodeGenerator() = default;
    void gen(string op, string result, string arg1 = string(), string arg2 = string());
    void gen(int label);

    string Quad2Str(const codeQuad &c) const;
    friend ostream &operator<<(ostream &os, const intCodeGenerator &t);

private:
    vector<codeQuad> ct;
};

class translator
{
private:
    string code;

public:
    translator();
    ~translator() = default;
    void addwidth(int width);
    shared_ptr<symbol_table> t = nullptr;
    stack<shared_ptr<symbol_table>> tblSt;
    stack<int> offsetSt;
    intCodeGenerator generator;
};

#endif
