// ref:https://blog.csdn.net/xzz_hust/article/details/45009147 https://blog.csdn.net/qq_24421591/article/details/50045933
%{

#include "translator.h"
extern int yyparse (void);
extern int yylex (void);
extern int yylineno;
extern void yyerror(char *s);
%}
%union{
struct AST* a;
}

%token <a> Le  Ge  Eq  Ne Def  And  Or  IntConstant RealConstant REAL  StringConstant  Identifier  Void  INT  WHILE  If  Else  Return Operator BEGIN_KEY END_KEY MAIN WRITE READ 
%type  <a> Programs Program MethodDecl FormalParams FormalParam Block Statements Statement LocalVarDecl 
Type AssignStmt  ReturnStmt IfStmt WriteStmt ReadStmt  BoolExpression Expression MultiplicativeExpr 
PrimaryExpr ActualParams WhileStmt

%left '+' '-'
%left '*' '/'
%left And Or

%%
Programs :
    Program{}
    ;
Program : MethodDecl {}
    |MethodDecl Program {}
    ;

MethodDecl : Type Identifier '(' FormalParams ')' Block{}
    | Type MAIN Identifier '(' FormalParams ')' Block{}
    ;
FormalParams : FormalParams  ',' FormalParam{}
    | FormalParam{}
    | /* empty */{}
    ;
FormalParam : Type Identifier{}
    ;


Block : BEGIN_KEY Statements END_KEY {}
    | error  { yyerror("keyword typo? \n"); }
    ;

Statements :Statements Statement{}
    | Statement{}
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



LocalVarDecl : Type Identifier ';' {}
    | Type AssignStmt  {}
    | Type error ';' { yyerror("Maybe missing Identifier? \n"); }
    ;

WhileStmt : WHILE '(' BoolExpression ')' Statement{}
    ;


Type : INT{}
    | REAL{}
    | StringConstant{}
    ;

AssignStmt  : Identifier Def Expression ';'{}
    |  Identifier Def StringConstant ';'{}
    | error ';' { yyerror("Maybe missing ';'? \n"); }
    ;
ReturnStmt : Return Expression ';'{}
    ;
IfStmt : If '(' BoolExpression ')' Statement{}
    | If '(' BoolExpression ')' Statement Else Statement{}
    ;
WriteStmt : WRITE '(' Expression ',' StringConstant ')' ';'{}
    | WRITE error ';' { yyerror("Maybe missing Identifier or StringConstant? \n"); }
    ;
ReadStmt  : READ '(' Identifier ',' StringConstant ')' ';'{}
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

Expression : Expression  '+' MultiplicativeExpr {}
    | Expression '-' MultiplicativeExpr{}
    | MultiplicativeExpr{}
    | error ';' { yyerror("Maybe missing ';' or operand? \n"); }
    ;
MultiplicativeExpr : MultiplicativeExpr '*' PrimaryExpr{}
    | MultiplicativeExpr '/'  PrimaryExpr{}
    | PrimaryExpr{}
    ;
PrimaryExpr : IntConstant {}
    | RealConstant {}
    | Identifier {}
    | '(' Expression ')' {}
    | Identifier '(' ActualParams ')'{}
    ;
ActualParams : ActualParams  ',' Expression{}
    |  Expression{}
    ;
%%