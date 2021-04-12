%{
#include<unistd.h>
#include<stdio.h> 
#include "gramtree.h"
%}

%union{
struct ast* a;
}

%token <a> Le  Ge  Eq  Ne Def  And  Or  IntConstant Real  StringConstant  IDENTIFIER  Void  Int  While  If  Else  Return OP BEGIN_KEY END_KEY MAIN WRITE READ
%type  <a> Programs Program MethodDecl FormalParams FormalParam Block Statements Statement LocalVarDecl 
Type AssignStmt  ReturnStmt IfStmt WriteStmt ReadStmt  BoolExpression Expression MultiplicativeExpr 
PrimaryExpr ActualParams

%%
Programs :
    Program{$$=newast("Program",1,$1);printf("打印语法树 :\n");eval($$,0);printf("syntax tree打印完毕!\n\n");}
    ;
Program : MethodDecl {$$=newast("Program",1,$1);}
    |MethodDecl Program {$$=newast("Program",2,$1,$2);}
    ;

MethodDecl : Type IDENTIFIER '(' FormalParams ')' Block{$$=newast("MethodDecl",5,$1,$2,$4,$6);}
    | Type MAIN IDENTIFIER '(' FormalParams ')' Block{$$=newast("MethodDecl",5,$1,$2,$3,$5,$7);}
    ;
FormalParams : FormalParams  ',' FormalParam{$$=newast("FormalParams",2,$1,$3);}
    | FormalParam{$$=newast("FormalParams",1,$1);}
    | /* empty */{$$=newast("FormalParams",0,-1);}
    ;
FormalParam : Type IDENTIFIER{$$=newast("FormalParam",2,$1,$2);}
    ;


Block : BEGIN_KEY Statements END_KEY {$$=newast("Block",3,$1,$2,$3);}
    ;

Statements :Statements Statement{$$=newast("Statements",2,$1,$2);}
        | Statement{$$=newast("Statements",1,$1);}
        ;

Statement : Block{$$=newast("Block",1,$1);}
        | LocalVarDecl{$$=newast("LocalVarDecl",1,$1);}
        | AssignStmt{$$=newast("AssignStmt",1,$1);}
        | ReturnStmt{$$=newast("ReturnStmt",1,$1);}
        | IfStmt{$$=newast("IfStmt",1,$1);}
	    | WriteStmt{$$=newast("WriteStmt",1,$1);}
	    | ReadStmt{$$=newast("ReadStmt",1,$1);}
        ;


LocalVarDecl : Type IDENTIFIER ';' {$$=newast("IDENTIFIER",2,$1,$2);}
        | Type AssignStmt  {$$=newast("IDENTIFIER",2,$1,$2);}
        ;

Type : Int{$$=newast("Type",1,$1);}
    | Real{$$=newast("Type",1,$1);}
    | StringConstant{$$=newast("Type",1,$1);}
    ;

AssignStmt  : IDENTIFIER Def Expression ';'{$$=newast("AssignStmt",3,$1,$2,$3);}
           |  IDENTIFIER Def StringConstant ';'{$$=newast("AssignStmt",3,$1,$2,$3);}
        ;
ReturnStmt : Return Expression ';'{$$=newast("ReturnStmt",2,$1,$2);}
        ;
IfStmt    : If '(' BoolExpression ')' Statement{$$=newast("IfStmt",3,$1,$3,$5);}
            | If '(' BoolExpression ')' Statement Else Statement{$$=newast("IfStmt",5,$1,$3,$5,$6,$7);}
        ;
WriteStmt : WRITE '(' Expression ',' StringConstant ')' ';'{$$=newast("WriteStmt",3,$1,$3,$5);}
        ;
ReadStmt  : READ '(' IDENTIFIER ',' StringConstant ')' ';'{$$=newast("ReadStmt",3,$1,$3,$5);}
        ;

BoolExpression : Expression Eq Expression {$$=newast("BoolExpression",3,$1,$2,$3);}
                 |Expression Ne Expression {$$=newast("BoolExpression",3,$1,$2,$3);}
                 ;

Expression : Expression   '+' MultiplicativeExpr {$$=newast("Expression",2,$1,$3);}
            | Expression '-' MultiplicativeExpr{$$=newast("Expression",2,$1,$3);}
            | MultiplicativeExpr{$$=newast("Expression",1,$1);}
            ;
MultiplicativeExpr : MultiplicativeExpr '*' PrimaryExpr{$$=newast("MultiplicativeExpr",2,$1,$3);}
            | MultiplicativeExpr '/'  PrimaryExpr{$$=newast("MultiplicativeExpr",2,$1,$3);}
            | PrimaryExpr{$$=newast("MultiplicativeExpr",1,$1);}
            ;
PrimaryExpr : IntConstant {$$=newast("PrimaryExpr",1,$1);}
             | Real {$$=newast("PrimaryExpr",1,$1);}
             | IDENTIFIER {$$=newast("PrimaryExpr",1,$1);}
             | '(' Expression ')' {$$=newast("PrimaryExpr",1,$2);}
             | IDENTIFIER '(' ActualParams ')'{$$=newast("PrimaryExpr",2,$1,$3);}
             ;
ActualParams : ActualParams  ',' Expression{$$=newast("ActualParams",2,$1,$3);}
            |  Expression{$$=newast("ActualParams",1,$1);}
            ;
%%