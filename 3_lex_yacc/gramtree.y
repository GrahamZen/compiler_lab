%{
#include "gramtree.h"
%}


%%
Program : MethodDecl MethodDecl* 
Type : INT | REAL |STRING 
MethodDecl : Type [MAIN] Id '(' FormalParams ')' Block
FormalParams : [FormalParam ( ',' FormalParam )* ]
FormalParam : Type Id

Block : BEGIN Statement+ END

Statement : Block
           | LocalVarDecl  
           | AssignStmt   
           | ReturnStmt
           | IfStmt
	   | WriteStmt
	   | ReadStmt
        
LocalVarDecl : Type Id ';' | Type AssignStmt  

AssignStmt  : Id := Expression ';'
           |  Id := QString ';'
ReturnStmt : RETURN Expression ';'
IfStmt    : IF '(' BoolExpression ')' Statement
            | IF '(' BoolExpression ')' Statement ELSE Statement
WriteStmt : WRITE '(' Expression ',' QString ')' ';'
ReadStmt  : READ '(' Id ',' QString ')' ';'
QString is any sequence of characters except double quote itself, enclosed in double quotes.

%%