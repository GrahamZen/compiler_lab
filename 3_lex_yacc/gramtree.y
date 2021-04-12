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
Type AssignStmt  ReturnStmt IfStmt    WriteStmt ReadStmt  BoolExpression Expression MultiplicativeExpr 
PrimaryExpr ActualParams

%%
Programs :
    Program
    ;
Program : MethodDecl 
    |MethodDecl Program 
    ;

MethodDecl : Type IDENTIFIER '(' FormalParams ')' Block
    | Type MAIN IDENTIFIER '(' FormalParams ')' Block
    ;
FormalParams : FormalParams  ',' FormalParam
    | FormalParam
    | /* empty */
    ;
FormalParam : Type IDENTIFIER
    ;


Block : BEGIN_KEY Statements END_KEY 
    ;

Statements :Statements Statement
        | Statement
        ;

Statement : Block
        | LocalVarDecl  
        | AssignStmt   
        | ReturnStmt
        | IfStmt
	    | WriteStmt
	    | ReadStmt
        ;


LocalVarDecl : Type IDENTIFIER ';' 
        | Type AssignStmt  
        ;

Type : Int
    | Real 
    | StringConstant 
    ;

AssignStmt  : IDENTIFIER Def Expression ';'
           |  IDENTIFIER Def StringConstant ';'
        ;
ReturnStmt : Return Expression ';'
        ;
IfStmt    : If '(' BoolExpression ')' Statement
            | If '(' BoolExpression ')' Statement Else Statement
        ;
WriteStmt : WRITE '(' Expression ',' StringConstant ')' ';'
        ;
ReadStmt  : READ '(' IDENTIFIER ',' StringConstant ')' ';'
        ;

BoolExpression : Expression Eq Expression 
                 |Expression Ne Expression 
                 ;

Expression : Expression   '+' MultiplicativeExpr 
            | Expression '-' MultiplicativeExpr
            | MultiplicativeExpr
            ;
MultiplicativeExpr : MultiplicativeExpr '*' PrimaryExpr
            | MultiplicativeExpr '/'  PrimaryExpr
            | PrimaryExpr
            ;
PrimaryExpr : IntConstant 
             | Real 
             | IDENTIFIER 
             | '(' Expression ')' 
             | IDENTIFIER '(' ActualParams ')'
             ;
ActualParams : ActualParams  ',' Expression
            |  Expression
            ;
%%