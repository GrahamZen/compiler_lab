#ifndef TRANSLATOR_H
#define TRANSLATOR_H
#include <iostream>
#include <iomanip>
#include <memory>
#include <stack>
#include <map>
#include <queue>
// #include "syn_tree.tab.h"
using namespace std;

extern int yylineno;
extern char *yytext;

struct node
{
    int lineNo; 
    string name;//type name
    string idName;
    int intVal=0;
    float floatVal=0;
};

node* createNode(char *name, int lineno);
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
    symbol_table(){
        cout<<"symbol_table created.\n";
    }
    symbol_table(shared_ptr<symbol_table> t);
    ~symbol_table(){cout<<"symbol_table destroyed.\n";};
    bool enter(string lexeme, string type, int offset);
    bool enterproc(string lexeme, shared_ptr<symbol_table> fptr);
    void addwidth(int width);
    int size()const;
    const map<string,symbol_table::entry>&table()const;
    friend ostream &operator<<(ostream &os, shared_ptr<symbol_table> t);
private:
    map<string,entry> _table;
    shared_ptr<symbol_table> prev = nullptr;
    int _size = 0;

};

shared_ptr<symbol_table> mktable(shared_ptr<symbol_table> t);
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
    void gen(string sentence);
};

#endif
