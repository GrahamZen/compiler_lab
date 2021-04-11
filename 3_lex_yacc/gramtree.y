%{
#include<unistd.h>
#include<stdio.h>   
#include "gramtree.h"
%}

%union{
struct ast* a;
double d;
}

%token  Le  Ge  Eq  Ne Def  And  Or  IntConstant Real 
    StringConstant  IDENTIFIER  Void  Int  While 
    If  Else  Return   Print 
    ReadInt OP BEGIN_KEY END_KEY DECLARE MAIN WRITE READ

%%
Program : MethodDecl Program| /* empty */
Type : Int
    | Real 
    | StringConstant 
MethodDecl : Type IDENTIFIER '(' FormalParams ')' Block
    | Type IDENTIFIER '(' ')' Block
FormalParams : FormalParam
    | FormalParam  ',' FormalParams
FormalParam : Type IDENTIFIER

Block : BEGIN_KEY Statement END_KEY

Statement : Block
        | LocalVarDecl  
        | AssignStmt   
        | ReturnStmt
        | IfStmt
	    | WriteStmt
	    | ReadStmt
        
LocalVarDecl : Type IDENTIFIER ';' 
        | Type AssignStmt  

AssignStmt  : IDENTIFIER Def Expression ';'
           |  IDENTIFIER Def StringConstant ';'
ReturnStmt : Return Expression ';'
IfStmt    : If '(' BoolExpression ')' Statement
            | If '(' BoolExpression ')' Statement Else Statement
WriteStmt : WRITE '(' Expression ',' StringConstant ')' ';'
ReadStmt  : READ '(' IDENTIFIER ',' StringConstant ')' ';'

Expression : MultiplicativeExpr   '+' 
            | '-' Expression
MultiplicativeExpr : PrimaryExpr '*' MultiplicativeExpr
            | PrimaryExpr '/'  MultiplicativeExpr
            | PrimaryExpr
PrimaryExpr : Int
             | Real
             | IDENTIFIER            
             | '(' Expression ')'
            //  | IDENTIFIER '(' ActualParams ')'
BoolExpression : Expression Eq Expression 
                 |Expression Ne Expression   
// ActualParams : [Expression ( ',' Expression)*]
%%