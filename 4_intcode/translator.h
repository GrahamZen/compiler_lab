#ifndef TRANSLATOR_H
#define TRANSLATOR_H
#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <stack>
#include <list>
#include <string>
#include <vector>
// #include "syn_tree.tab.h"
using namespace std;

extern int yylineno;
extern char *yytext;

struct node
{
    node()=default;
    node(int lineNo, const node &n,string next=string(),list<string> True=list<string>(),list<string> False=list<string>()){*this=n;_lineNo=lineNo;_next=next;_True=True;_False=False;}
    explicit node(int lineNo,string addr=string(),string code=string()):_lineNo(lineNo),_addr(addr),_code(code){}
    int _lineNo;
    string typeName; //type name
    string idName;
    int intVal = 0;
    float floatVal = 0;
    string _code;
    string _addr;
    list<string> _True,_False;
    string _next;
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
        bool isMain;
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
    bool enterproc(string lexeme, shared_ptr<symbol_table> fptr,bool isMain=false);
    void addwidth(int width);
    string newTemp();
    string newLabel();
    string lookup(string idName,bool errFlag);
    int size() const;
    const map<string, symbol_table::entry> &table() const;
    friend ostream &operator<<(ostream &os, shared_ptr<symbol_table> t);

private:
    map<string, entry> _table;
    shared_ptr<symbol_table> prev = nullptr;
    int _size = 0;
    int tmpCnt=0;
    int labelCnt=0;
};

shared_ptr<symbol_table> mktable(shared_ptr<symbol_table> t);

class intCodeGenerator
{
public:
    struct codeQuad
    {
        string _op, _arg1, _arg2, _result;
        string _label;
        bool isLabel;
        codeQuad(string op, string result, string arg1 = string(), string arg2 = string()) : _op(op), _result(result), isLabel(false)
        {
            if (!arg1.empty())
                _arg1 = arg1;
            if (!arg2.empty())
                _arg2 = arg2;
        }
        codeQuad(string label) : _label(label), isLabel(true) {}
    };
    intCodeGenerator() = default;
    ~intCodeGenerator() = default;
    void gen(string op, string result, string arg1 = string(), string arg2 = string());
    void gen(string label);

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
    string lookup(string idName,bool errFlag=true){
        return tblSt.top()->lookup(idName,errFlag);
    }
    string newTemp(){
        return tblSt.top()->newTemp();
    }
    string newLabel(){
        return tblSt.top()->newLabel();
    }
    void label(string &l){
        auto nl=newLabel();
        generator.gen(nl);
        l=nl;
    }
};

#endif
