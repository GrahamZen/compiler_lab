// ref:https://blog.csdn.net/xzz_hust/article/details/45009147 
// Three-Address Code:https://www.csd.uwo.ca/~mmorenom/CS447/Lectures/IntermediateCode.html/node3.html
%{

#include "translator.h"
#include <cstring>
extern int yyparse (void);
extern int yylex (void);
extern int yylineno;
extern void yyerror(char *s);
extern translator global_tab;
extern std::string tmpIdName;
extern std::map<string,int>type2size;
extern bool isTypeDef;
extern int funcArgNum;
%}
%union{
struct node* a;
}

%token <a> Le  Ge  Eq  Ne Def  And  Or  IntConstant RealConstant REAL  StringConstant  Identifier  Void  INT  WHILE  If  Else  Return Operator BEGIN_KEY END_KEY MAIN WRITE READ 
%type  <a> Programs Program MethodDecl FormalParams FormalParam Block Statements Statement LocalVarDecl 
Type AssignStmt  ReturnStmt IfStmt WriteStmt ReadStmt  BoolExpression Expression ActualParams WhileStmt

%left '+' '-'
%left '*' '/'
%left And Or

%%
Programs :
    {global_tab.tblSt.push(global_tab.t);global_tab.offsetSt.push(0);}Program{global_tab.tblSt.top()->addwidth(global_tab.offsetSt.top());global_tab.tblSt.pop();global_tab.offsetSt.pop();cout<<global_tab.t;cout<<global_tab.generator<<endl;}
    ;

Program : MethodDecl {}
    |MethodDecl Program {}
    ;

MethodDecl :N Type Identifier O '(' FormalParams ')'  Block{
        auto tmp=global_tab.tblSt.top();
        tmp->addwidth(global_tab.offsetSt.top());
        global_tab.tblSt.pop();
        global_tab.offsetSt.pop();
        global_tab.tblSt.top()->enterproc($3->idName,tmp);
    }
    |N Type MAIN Identifier O '(' FormalParams ')'  Block{
        auto tmp=global_tab.tblSt.top();
        tmp->addwidth(global_tab.offsetSt.top());
        global_tab.tblSt.pop();
        global_tab.offsetSt.pop();
        global_tab.tblSt.top()->enterproc($4->idName,tmp,true);
    }
    ;
N: /* empty */{auto t=mktable(global_tab.tblSt.top());
                global_tab.tblSt.push(t);
                global_tab.offsetSt.push(0);}
    ;
O: /* empty */{global_tab.generator.gen(tmpIdName);}
    ;


FormalParams : FormalParams  ',' FormalParam{}
    | FormalParam{}
    | /* empty */{}
    ;
FormalParam : Type Identifier{global_tab.tblSt.top()->enter($2->idName,$1->typeName,global_tab.offsetSt.top());global_tab.addwidth(type2size[$1->typeName]);}
    ;


Block : BEGIN_KEY Statements END_KEY {}
    | error  { yyerror("keyword typo? \n"); }
    ;

Statements :Statements Statement{}
    | Statement{}
    | /* empty */{}
    ;

Statement : Block{}
    | LocalVarDecl{}
    | AssignStmt{}
    | ReturnStmt{}
    | IfStmt{}
    | WriteStmt{}
    | ReadStmt{}
    | WhileStmt{}
    ;



LocalVarDecl : Type Identifier ';' {
    if(!global_tab.lookup($2->idName,false).empty()){
        auto msg=string("duplicated definition for ")+$2->idName;
        char*str=new char[msg.size()];
        strcpy(str,msg.c_str());
        yyerror(str);
        delete[]str;
    }
    global_tab.tblSt.top()->enter($2->idName,$1->typeName,global_tab.offsetSt.top());
    global_tab.addwidth(type2size[$1->typeName]);}
    | Type AssignStmt  {global_tab.tblSt.top()->enter(tmpIdName,$1->typeName,global_tab.offsetSt.top());
                        global_tab.addwidth(type2size[$1->typeName]);}
    | Type error ';' { yyerror("Maybe missing Identifier? \n"); }
    ;

WhileStmt : WHILE '(' BoolExpression ')' Statement{}
    ;


Type : INT{isTypeDef=true;}
    | REAL{isTypeDef=true;}
    | StringConstant{}
    ;

AssignStmt  : Identifier Def Expression ';'{
    tmpIdName=$1->idName;
    if(isTypeDef){global_tab.generator.gen("=",$1->idName,$3->_addr);isTypeDef=false;}
    else
        global_tab.generator.gen("=",global_tab.lookup($1->idName),$3->_addr);
    }
    |  Identifier Def StringConstant ';'{tmpIdName=$1->idName;global_tab.generator.gen("=",$1->idName,$3->idName);}
    | error ';' { yyerror("Maybe missing ';'? \n"); }
    ;
ReturnStmt : Return Expression ';'{global_tab.generator.gen("return",$2->_addr);}
    ;
IfStmt : If '(' BoolExpression ')' Statement{}
    | If '(' BoolExpression ')' Statement Else Statement{}
    ;


WriteStmt : WRITE '(' Expression ',' StringConstant ')' ';'{$$=new node(yylineno,global_tab.newTemp());
global_tab.generator.gen("param",$3->_addr);
global_tab.generator.gen("param",$5->idName);
global_tab.generator.gen("write","2");}
    | WRITE error ';' { yyerror("Maybe missing Identifier or StringConstant? \n"); }
    ;
ReadStmt  : READ '(' Identifier ',' StringConstant ')' ';'{$$=new node(yylineno,global_tab.newTemp());
global_tab.generator.gen("param",$3->_addr);
global_tab.generator.gen("param",$5->idName);
global_tab.generator.gen("read","2");}
    | READ error ';' { yyerror("Maybe missing Identifier or StringConstant? \n"); }
    ;

BoolExpression : Expression Eq Expression {}
    | Expression Ne Expression {}
    | Expression '>' Expression{}
    | Expression '<' Expression{}
    | Expression Le Expression{}
    | Expression Ge Expression{}
    | BoolExpression And BoolExpression{}
    | BoolExpression Or BoolExpression{}
    ;

Expression : Expression  '+' Expression {$$=new node(yylineno,global_tab.newTemp());global_tab.generator.gen("+",$$->_addr,$1->_addr,$3->_addr);}
    | Expression '-' Expression{$$=new node(yylineno,global_tab.newTemp());global_tab.generator.gen("-",$$->_addr,$1->_addr,$3->_addr);}
    | Expression '*' Expression{$$=new node(yylineno,global_tab.newTemp());global_tab.generator.gen("*",$$->_addr,$1->_addr,$3->_addr);}
    | Expression '/' Expression{$$=new node(yylineno,global_tab.newTemp());global_tab.generator.gen("/",$$->_addr,$1->_addr,$3->_addr);}
    | IntConstant {$$=new node(yylineno,to_string($1->intVal));}
    | RealConstant {$$=new node(yylineno,to_string($1->floatVal));}
    | Identifier {$$=new node(yylineno,global_tab.lookup($1->idName));}
    | '(' Expression ')' {$$=new node(yylineno,*$2);}
    | Identifier '(' ActualParams ')'{$$=new node(yylineno,global_tab.newTemp());global_tab.generator.gen("call",$$->_addr,$1->idName,to_string(funcArgNum));funcArgNum=0;}//TODO:lookup for funcName
    | error ';' { yyerror("Maybe missing ';' or operand? \n"); }
    ;

ActualParams : ActualParams  ',' Expression{global_tab.generator.gen("param",$3->_addr);funcArgNum++;}
    |  Expression{global_tab.generator.gen("param",$1->_addr);funcArgNum++;}
    ;
%%