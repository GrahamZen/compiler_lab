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
    explicit node(int lineNo, const node &n){*this=n;_lineNo=lineNo;if(!n._nextlist)_nextlist=make_shared<list<int>>();}
    explicit node(int lineNo, const node &n,shared_ptr<list<int>> truelist,shared_ptr<list<int>> falselist,shared_ptr<list<int>>nextlist){*this=n;_lineNo=lineNo;_truelist=truelist;_falselist=falselist;_nextlist=nextlist;}
    explicit node(int lineNo, shared_ptr<list<int>> truelist,shared_ptr<list<int>> falselist,shared_ptr<list<int>> nextlist){_lineNo=lineNo;_truelist=truelist;_falselist=falselist;_nextlist=nextlist;}
    explicit node(int lineNo, int quad):_lineNo(lineNo),_quad(quad){}
    explicit node(int lineNo,string addr=string(),string code=string()):_lineNo(lineNo),_addr(addr),_code(code){}
    explicit node(int lineNo,vector<string>typeStack):_lineNo(lineNo),_typeStack(typeStack){}
    explicit node(int lineNo, const node &n, string type):_lineNo(lineNo){*this=n;_lineNo=lineNo;_typeStack.push_back(type);}
    int _lineNo;
    string typeName; //type name
    string idName;
    int intVal = 0;
    float floatVal = 0;
    string _code;
    string _addr;
    shared_ptr<list<int>> _truelist,_falselist,_nextlist;
    vector<string>_typeStack;
    int _quad=0;
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
        shared_ptr<vector<string>> typeStack;
        shared_ptr<symbol_table> fptr;
        string retType;
    };
    symbol_table()=default;
    symbol_table(shared_ptr<symbol_table> t);
    ~symbol_table()=default;
    bool enter(string lexeme, string type, int offset);
    bool enterproc(string lexeme, string retType, shared_ptr<symbol_table> fptr,vector<string>param, bool isMain=false);
    void addwidth(int width);
    string newTemp();
    string lookup(string idName,bool errFlag);
    shared_ptr<entry> getEntry(string idName,bool errFlag);
    int size() const;
    const map<string, symbol_table::entry> &table() const;
    friend ostream &operator<<(ostream &os, shared_ptr<symbol_table> t);

private:
    map<string, entry> _table;
    shared_ptr<symbol_table> prev = nullptr;
    int _size = 0;
    int tmpCnt=0;
};

shared_ptr<symbol_table> mktable(shared_ptr<symbol_table> t);


class translator;
class intCodeGenerator
{
public:
    friend class translator;
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
    intCodeGenerator& postProcess();

    friend ostream &operator<<(ostream &os, const intCodeGenerator &t);
    int quadCnt(){return ct.size();}
private:
    string Quad2Str(const codeQuad &c) const;
    vector<codeQuad> ct;
    int labelCnt=0;
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
    string lookup(string idName,int floor=0,bool errFlag=true){
        auto stCp=tblSt;
        while (floor-->0){
            if(stCp.empty())throw invalid_argument("exceeded stack's size.");
            stCp.pop();
        }
        return stCp.top()->lookup(idName,errFlag);
    }
    shared_ptr<symbol_table::entry> getEntry(string idName,int floor=0,bool errFlag=true){
        auto stCp=tblSt;
        while (floor-->0){
            if(stCp.empty())throw invalid_argument("exceeded stack's size.");
            stCp.pop();
        }
        return stCp.top()->getEntry(idName,errFlag);
    }
    string newTemp(){
        return tblSt.top()->newTemp();
    }
    int nextQuad(){return generator.quadCnt();}
    void backpatch(shared_ptr<list<int>>l,int quad);
};

shared_ptr<list<int>> mkList(int label);

string typeExpand(string type1,string type2);

#endif
