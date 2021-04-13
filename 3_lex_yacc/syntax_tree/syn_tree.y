// ref:https://blog.csdn.net/xzz_hust/article/details/45009147 https://blog.csdn.net/qq_24421591/article/details/50045933
%require "3.2"
%language "c++"
%{
#include<unistd.h>
#include<stdio.h> 
#include "syn_tree.h"
%}
%union{
struct AST* a;
}

%token <a> Le  Ge  Eq  Ne Def  And  Or  IntConstant Real  StringConstant  Identifier  Void  Int  WHILE  If  Else  Return Operator BEGIN_KEY END_KEY MAIN WRITE READ 
%type  <a> Programs Program MethodDecl FormalParams FormalParam Block Statements Statement LocalVarDecl 
Type AssignStmt  ReturnStmt IfStmt WriteStmt ReadStmt  BoolExpression Expression MultiplicativeExpr 
PrimaryExpr ActualParams WhileStmt

%left '+' '-'
%left '*' '/'
%left And Or

%%
Programs :
    Program{$$=createASTNode("Programs",1,$1);printf("Syntax tree :\n");traverse($$,0);destroy($$);}
    ;
Program : MethodDecl {$$=createASTNode("Program",1,$1);}
    |MethodDecl Program {$$=createASTNode("Program",2,$1,$2);}
    ;

MethodDecl : Type Identifier '(' FormalParams ')' Block{$$=createASTNode("MethodDecl",4,$1,$2,$4,$6);}
    | Type MAIN Identifier '(' FormalParams ')' Block{$$=createASTNode("MethodDecl",5,$1,$2,$3,$5,$7);}
    ;
FormalParams : FormalParams  ',' FormalParam{$$=createASTNode("FormalParams",2,$1,$3);}
    | FormalParam{$$=createASTNode("FormalParams",1,$1);}
    | /* empty */{$$=createASTNode("FormalParams",0,-1);}
    ;
FormalParam : Type Identifier{$$=createASTNode("FormalParam",2,$1,$2);}
    ;


Block : BEGIN_KEY Statements END_KEY {$$=createASTNode("Block",3,$1,$2,$3);}
    | error  { yyerror("keyword typo? \n"); }
    ;

Statements :Statements Statement{$$=createASTNode("Statements",2,$1,$2);}
    | Statement{$$=createASTNode("Statements",1,$1);}
    ;

Statement : Block{$$=createASTNode("Statement",1,$1);}
    | LocalVarDecl{$$=createASTNode("Statement",1,$1);}
    | AssignStmt{$$=createASTNode("Statement",1,$1);}
    | ReturnStmt{$$=createASTNode("Statement",1,$1);}
    | IfStmt{$$=createASTNode("Statement",1,$1);}
    | WriteStmt{$$=createASTNode("Statement",1,$1);}
    | ReadStmt{$$=createASTNode("Statement",1,$1);}
    | WhileStmt{$$=createASTNode("Statement",1,$1);}
    ;



LocalVarDecl : Type Identifier ';' {$$=createASTNode("LocalVarDecl",2,$1,$2);}
    | Type AssignStmt  {$$=createASTNode("LocalVarDecl",2,$1,$2);}
    | Type error ';' { yyerror("Maybe missing Identifier? \n"); }
    ;

WhileStmt : WHILE '(' BoolExpression ')' Statement{$$=createASTNode("WhileStmt",3,$1,$3,$5);}
    ;


Type : Int{$$=createASTNode("Type",1,$1);}
    | Real{$$=createASTNode("Type",1,$1);}
    | StringConstant{$$=createASTNode("Type",1,$1);}
    ;

AssignStmt  : Identifier Def Expression ';'{$$=createASTNode("AssignStmt",3,$1,$2,$3);}
    |  Identifier Def StringConstant ';'{$$=createASTNode("AssignStmt",3,$1,$2,$3);}
    | error ';' { yyerror("Maybe missing ';'? \n"); }
    ;
ReturnStmt : Return Expression ';'{$$=createASTNode("ReturnStmt",2,$1,$2);}
    ;
IfStmt : If '(' BoolExpression ')' Statement{$$=createASTNode("IfStmt",3,$1,$3,$5);}
    | If '(' BoolExpression ')' Statement Else Statement{$$=createASTNode("IfStmt",5,$1,$3,$5,$6,$7);}
    ;
WriteStmt : WRITE '(' Expression ',' StringConstant ')' ';'{$$=createASTNode("WriteStmt",3,$1,$3,$5);}
    | WRITE error ';' { yyerror("Maybe missing Identifier or StringConstant? \n"); }
    ;
ReadStmt  : READ '(' Identifier ',' StringConstant ')' ';'{$$=createASTNode("ReadStmt",3,$1,$3,$5);}
    | READ error ';' { yyerror("Maybe missing Identifier or StringConstant? \n"); }
    ;

BoolExpression : Expression Eq Expression {$$=createASTNode("BoolExpression",3,$1,$2,$3);}
    | Expression Ne Expression {$$=createASTNode("BoolExpression",3,$1,$2,$3);}
    | Expression '>' Expression{$$=createASTNode("BoolExpression",3,$1,createASTNode("Operator(>)",0,yylineno),$3);}
    | Expression '<' Expression{$$=createASTNode("BoolExpression",3,$1,createASTNode("Operator(<)",0,yylineno),$3);}
    | Expression Le Expression{$$=createASTNode("BoolExpression",3,$1,$2,$3);}
    | Expression Ge Expression{$$=createASTNode("BoolExpression",3,$1,$2,$3);}
    | BoolExpression And BoolExpression{$$=createASTNode("BoolExpression",3,$1,$2,$3);}
    | BoolExpression Or BoolExpression{$$=createASTNode("BoolExpression",3,$1,$2,$3);}
    ;

Expression : Expression  '+' MultiplicativeExpr {$$=createASTNode("Expression",3,$1,createASTNode("Operator(+)",0,yylineno),$3);}
    | Expression '-' MultiplicativeExpr{$$=createASTNode("Expression",3,$1,createASTNode("Operator(-)",0,yylineno),$3);}
    | MultiplicativeExpr{$$=createASTNode("Expression",1,$1);}
    | error ';' { yyerror("Maybe missing ';' or operand? \n"); }
    ;
MultiplicativeExpr : MultiplicativeExpr '*' PrimaryExpr{$$=createASTNode("MultiplicativeExpr",3,$1,createASTNode("Operator(*)",0,yylineno),$3);}
    | MultiplicativeExpr '/'  PrimaryExpr{$$=createASTNode("MultiplicativeExpr",3,$1,createASTNode("Operator(/)",0,yylineno),$3);}
    | PrimaryExpr{$$=createASTNode("MultiplicativeExpr",1,$1);}
    ;
PrimaryExpr : IntConstant {$$=createASTNode("PrimaryExpr",1,$1);}
    | Real {$$=createASTNode("PrimaryExpr",1,$1);}
    | Identifier {$$=createASTNode("PrimaryExpr",1,$1);}
    | '(' Expression ')' {$$=createASTNode("PrimaryExpr",1,$2);}
    | Identifier '(' ActualParams ')'{$$=createASTNode("PrimaryExpr",2,$1,$3);}
    ;
ActualParams : ActualParams  ',' Expression{$$=createASTNode("ActualParams",2,$1,$3);}
    |  Expression{$$=createASTNode("ActualParams",1,$1);}
    ;
%%