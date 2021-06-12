// ref:https://blog.csdn.net/xzz_hust/article/details/45009147 https://blog.csdn.net/qq_24421591/article/details/50045933
%{

#include "translator.h"
extern int yyparse (void);
extern int yylex (void);
extern int yylineno;
extern void yyerror(char *s);
extern translator global_tab;
extern std::string tmpIdName;
extern std::map<string,int>type2size;

%}
%union{
struct node* a;
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
    M Program{global_tab.tblSt.top()->addwidth(global_tab.offsetSt.top());global_tab.tblSt.pop();global_tab.offsetSt.pop();cout<<global_tab.t.get();}
    ;
M: /* empty */{global_tab.tblSt.push(global_tab.t);global_tab.offsetSt.push(0);}
    ;
Program : MethodDecl {}
    |MethodDecl Program {}
    ;

MethodDecl :N Type Identifier '(' FormalParams ')' Block{
        auto tmp=global_tab.tblSt.top();
        tmp->addwidth(global_tab.offsetSt.top());
        global_tab.tblSt.pop();
        global_tab.offsetSt.pop();
        global_tab.tblSt.top()->enterproc($3->idName,tmp);
    }
    |N Type MAIN Identifier '(' FormalParams ')' Block{
        auto tmp=global_tab.tblSt.top();
        tmp->addwidth(global_tab.offsetSt.top());
        global_tab.tblSt.pop();
        global_tab.offsetSt.pop();
        global_tab.tblSt.top()->enterproc($4->idName+"<"+"MAIN"+">",tmp);
    }
    ;
N: /* empty */{auto t=mktable(global_tab.tblSt.top());
                global_tab.tblSt.push(t);
                global_tab.offsetSt.push(0);}
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



LocalVarDecl : Type Identifier ';' {global_tab.tblSt.top()->enter($2->idName,$1->name,global_tab.offsetSt.top());
                                    global_tab.addwidth(type2size[$1->name]);}
    | Type AssignStmt  {global_tab.tblSt.top()->enter(tmpIdName,$1->name,global_tab.offsetSt.top());
                        global_tab.addwidth(type2size[$1->name]);}
    | Type error ';' { yyerror("Maybe missing Identifier? \n"); }
    ;

WhileStmt : WHILE '(' BoolExpression ')' Statement{}
    ;


Type : INT{}
    | REAL{}
    | StringConstant{}
    ;

AssignStmt  : Identifier Def Expression ';'{tmpIdName=$1->idName;}
    |  Identifier Def StringConstant ';'{tmpIdName=$1->idName;}
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