// ref:https://blog.csdn.net/xzz_hust/article/details/45009147 
// Three-Address Code:https://www.csd.uwo.ca/~mmorenom/CS447/Lectures/IntermediateCode.html/node3.html
%{

#include "translator.h"
#include <fstream>
extern int yyparse (void);
extern int yylex (void);
extern int yylineno;
extern void yyerror(char *s);
extern translator global_tab;
extern std::string tmpIdName;
extern std::string tmpTypeName;
extern std::map<string,int>type2size;
extern bool isTypeDef;
extern int funcArgNum;
%}
%union{
struct node* a;
}

%token <a> Le  Ge  Eq  Ne Def  And  Or  IntConstant RealConstant REAL  StringConstant  Identifier  Void  INT  WHILE  If  Else  Return Operator BEGIN_KEY END_KEY MAIN WRITE READ RELOP
%type  <a> Programs Program MethodDecl FormalParams FormalParam Block Statements Statement LocalVarDecl 
Type AssignStmt  ReturnStmt IfStmt WriteStmt ReadStmt  BoolExpression Expression ActualParams WhileStmt M

%left '+' '-'
%left '*' '/'
%left And Or

%%
Programs :{global_tab.tblSt.push(global_tab.t);global_tab.offsetSt.push(0);}Program{global_tab.tblSt.top()->addwidth(global_tab.offsetSt.top());global_tab.tblSt.pop();global_tab.offsetSt.pop();
        ofstream codestm("test.ll");
        codestm<<global_tab.generator.postProcess()<<endl;
        ofstream symTabStm("symbolTable.txt");
        symTabStm<<global_tab.t<<endl;
    }
    ;

Program : MethodDecl {}
    |MethodDecl Program {}
    ;

MethodDecl :N Type{tmpTypeName=$2->typeName;} Identifier O '(' FormalParams ')'  Block{
        auto tmp=global_tab.tblSt.top();
        tmp->addwidth(global_tab.offsetSt.top());
        global_tab.tblSt.pop();
        global_tab.offsetSt.pop();
        global_tab.tblSt.top()->enterproc($4->idName,$2->typeName,tmp,$7->_typeStack);
    }
    |N Type{tmpTypeName=$2->typeName;} MAIN{if(global_tab.t->mainDeclared)yyerror("error: main function is declared.");
        global_tab.t->mainDeclared=true;} Identifier{if(global_tab.isDupVar($6->idName))yyerrorStr("error: redefinition of '"+$6->idName+'\'');} O '(' FormalParams ')'  Block
    {
        auto tmp=global_tab.tblSt.top();
        tmp->addwidth(global_tab.offsetSt.top());
        global_tab.tblSt.pop();
        global_tab.offsetSt.pop();
        global_tab.tblSt.top()->enterproc($6->idName,$2->typeName,tmp,$10->_typeStack,true);
    }
    ;
N: /* empty */{auto t=mktable(global_tab.tblSt.top());
                global_tab.tblSt.push(t);
                global_tab.offsetSt.push(0);
                }
    ;
O: /* empty */{global_tab.generator.gen(tmpIdName);}
    ;


FormalParams : FormalParams  ',' FormalParam{$$=new node(yylineno,*$1,$3->typeName);}
    | FormalParam{$$=new node(yylineno,vector<string>({$1->typeName}));}
    | /* empty */{}
    ;
FormalParam : Type Identifier{global_tab.tblSt.top()->enter($2->idName,$1->typeName,global_tab.offsetSt.top());global_tab.addwidth(type2size[$1->typeName]);
    $$->typeName=$1->typeName;
    }
    ;


Block : BEGIN_KEY Statements END_KEY {}
    | error  { yyerror("keyword typo?"); }
    ;

Statements :Statements M Statement{global_tab.backpatch($1->_nextlist,$2->_quad);$$=new node(yylineno,*$3);}
    | Statement{$$=new node(yylineno,*$1);}
    | /* empty */{}
    ;

Statement : Block{$$=new node(yylineno,*$1);}
    | LocalVarDecl{$$=new node(yylineno,*$1);}
    | AssignStmt{$$=new node(yylineno,*$1);}
    | ReturnStmt{$$=new node(yylineno,*$1);}
    | IfStmt{$$=new node(yylineno,*$1);}
    | WriteStmt{$$=new node(yylineno,*$1);}
    | ReadStmt{$$=new node(yylineno,*$1);}
    | WhileStmt{$$=new node(yylineno,*$1);}
    ;



LocalVarDecl : Type Identifier ';' {
    global_tab.tblSt.top()->enter($2->idName,$1->typeName,global_tab.offsetSt.top());
    global_tab.addwidth(type2size[$1->typeName]);
    
    }
    | Type AssignStmt  {if($1->typeName!=$2->typeName){
        yyerrorStr("error: cannot convert ‘"+ $2->typeName + "’ to ‘"+ $1->typeName + "’ in initialization");
    }
        global_tab.tblSt.top()->enter(tmpIdName,$1->typeName,global_tab.offsetSt.top());
                        global_tab.addwidth(type2size[$1->typeName]);}
    | Type error ';' { yyerror("Maybe missing Identifier?"); }
    ;

WhileStmt : WHILE M '(' BoolExpression ')' M Statement{
    global_tab.backpatch($7->_nextlist,$2->_quad);
    global_tab.backpatch($4->_truelist,$6->_quad);
    $$=new node(yylineno,make_shared<list<int>>(),make_shared<list<int>>(),make_shared<list<int>>(*$4->_falselist));
    global_tab.generator.gen("goto", to_string($2->_quad));
}
    ;


Type : INT{isTypeDef=true;}
    | REAL{isTypeDef=true;}
    | StringConstant{}
    ;

AssignStmt  : Identifier Def Expression ';'{
    tmpIdName=$1->idName;
    $$=new node(yylineno, *$3);
    if(isTypeDef){global_tab.generator.gen("=",$1->idName,$3->_addr);isTypeDef=false;}
    else
        global_tab.generator.gen("=",(global_tab.lookup($1->idName,0).empty()?"":$1->idName),$3->_addr);
    }
    |  Identifier Def StringConstant ';'{tmpIdName=$1->idName;global_tab.generator.gen("=",$1->idName,$3->idName);}
    | error ';' { yyerror("Maybe missing ';'?"); }
    ;
ReturnStmt : Return Expression ';'{global_tab.generator.gen("return",$2->_addr);
    if($2->typeName!=tmpTypeName){
    yyerrorStr("error: no viable conversion from returned value of type '"+ $2->typeName +"' to function return type '"+tmpTypeName+'\'');
    }}
    ;
IfStmt : 
    If '(' BoolExpression ')' M Statement {$<a>$=new node(yylineno,global_tab.nextQuad());$<a>$->_nextlist=mkList(global_tab.nextQuad());global_tab.generator.gen("goto","_");} Else M Statement{
    $$=new node(yylineno,make_shared<list<int>>(),make_shared<list<int>>(),make_shared<list<int>>(*$6->_nextlist));
    global_tab.backpatch($3->_truelist,$5->_quad);
    global_tab.backpatch($3->_falselist,$9->_quad);
    $$->_nextlist->merge(*$<a>7->_nextlist);
    $$->_nextlist->merge(*$10->_nextlist);
    }
    | If '(' BoolExpression ')' M Statement{
    $$=new node(yylineno,make_shared<list<int>>(),make_shared<list<int>>(),make_shared<list<int>>(*$3->_falselist));
    global_tab.backpatch($3->_truelist,$5->_quad);
    $$->_nextlist->merge(*$6->_nextlist);
}
    ;


WriteStmt : WRITE '(' Expression ',' StringConstant ')' ';'{$$=new node(yylineno,global_tab.newTemp());
global_tab.generator.gen("param",$3->_addr);
global_tab.generator.gen("param",$5->idName);
global_tab.generator.gen("write","2");}
    | WRITE error ';' { yyerror("Maybe missing Identifier or StringConstant?"); }
    ;
ReadStmt  : READ '(' Identifier ',' StringConstant ')' ';'{$$=new node(yylineno,global_tab.newTemp());
global_tab.generator.gen("param",$3->idName);
global_tab.generator.gen("param",$5->idName);
global_tab.generator.gen("read","2");}
    | READ error ';' { yyerror("Maybe missing Identifier or StringConstant?"); }
    ;

BoolExpression : Expression RELOP Expression{
    $$->_truelist=mkList(global_tab.nextQuad());
    $$->_falselist=mkList(global_tab.nextQuad()+1);
    global_tab.generator.gen($2->idName,"_",$1->_addr,$3->_addr);
    global_tab.generator.gen("goto","_");
}
    | BoolExpression And M BoolExpression{
        $$=new node(yylineno,make_shared<list<int>>(),make_shared<list<int>>(),make_shared<list<int>>());
        global_tab.backpatch($1->_truelist,$3->_quad);
        *$$->_truelist=*$4->_truelist;
        *$$->_falselist=*$1->_falselist;
        $$->_falselist->merge(*$4->_falselist);
    }
    | BoolExpression Or M BoolExpression{
        $$=new node(yylineno,make_shared<list<int>>(),make_shared<list<int>>(),make_shared<list<int>>());
        global_tab.backpatch($1->_falselist,$3->_quad);
        $$->_truelist=$1->_truelist;
        $$->_truelist->merge(*$4->_truelist);
        $$->_falselist=$4->_falselist;
    }
    ;

M : /* empty */{$$=new node(yylineno,global_tab.nextQuad());}
    ;
Expression : Expression  '+' Expression {$$=new node(yylineno,global_tab.newTemp());global_tab.generator.gen("+",$$->_addr,$1->_addr,$3->_addr);$$->typeName=typeExpand($1->typeName,$3->typeName);}
    | Expression '-' Expression{$$=new node(yylineno,global_tab.newTemp());global_tab.generator.gen("-",$$->_addr,$1->_addr,$3->_addr);$$->typeName=typeExpand($1->typeName,$3->typeName);}
    | Expression '*' Expression{$$=new node(yylineno,global_tab.newTemp());global_tab.generator.gen("*",$$->_addr,$1->_addr,$3->_addr);$$->typeName=typeExpand($1->typeName,$3->typeName);}
    | Expression '/' Expression{$$=new node(yylineno,global_tab.newTemp());global_tab.generator.gen("/",$$->_addr,$1->_addr,$3->_addr);$$->typeName=typeExpand($1->typeName,$3->typeName);}
    | IntConstant {$$=new node(yylineno,to_string($1->intVal));$$->typeName="INT";}
    | RealConstant {$$=new node(yylineno,to_string($1->floatVal));$$->typeName="REAL";}
    | Identifier {auto typeName=global_tab.lookup($1->idName,0);$$=new node(yylineno,(typeName.empty()?"":$1->idName));$$->typeName=typeName;}
    | '(' Expression ')' {$$=new node(yylineno,*$2);$$->typeName=$2->typeName;}
    | Identifier '(' ActualParams ')'{
        auto entry=global_tab.getEntry($1->idName,1);
        if(!entry||$3->_typeStack!=*entry->typeStack){
            yyerrorStr(string("error: no matching function for call to ") + $1->idName);
            $$=new node(yylineno,global_tab.newTemp());
            global_tab.generator.gen("call",$$->_addr,$1->idName,to_string(funcArgNum));
            funcArgNum=0;
        }else{
            $$=new node(yylineno,global_tab.newTemp());
            $$->typeName=entry->retType;
            global_tab.generator.gen("call",$$->_addr,$1->idName,to_string(funcArgNum));
            funcArgNum=0;
        }
    }
    | error ';' { yyerror("expected primary-expression before ‘;’ token"); }
    ;

ActualParams : ActualParams  ',' Expression{global_tab.generator.gen("param",$3->_addr);funcArgNum++;$$->_typeStack.push_back($3->typeName);}
    |  Expression{global_tab.generator.gen("param",$1->_addr);funcArgNum++;$$->_typeStack={$1->typeName};}
    ;
%%