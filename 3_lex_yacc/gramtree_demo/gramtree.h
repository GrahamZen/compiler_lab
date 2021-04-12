/*
*Name:gramtree.h
*Author:WangLin
*Created on:2015-10-03
*Function:定义语法树结点结构体&变长参数构造树&遍历树函数
*/
/*来自于词法分析器*/
extern int yylineno;//行号
extern char* yytext;//词
void yyerror(char *s,...);//错误处理函数

/*抽象语法树的结点*/
struct ast
{
    int line; //行号
    char* name;//语法单元的名字
    struct ast *l;//左孩子
    struct ast *r;//右孩子
    union//共用体用来存放ID/TYPE/INTEGER/FLOAT结点的值
    {
    char* idtype;
    int intgr;
    float flt;
    };
};

/*构造抽象语法树,变长参数，name:语法单元名字；num:变长参数中语法结点个数*/
struct ast *newast(char* name,int num,...);

/*遍历抽象语法树，level为树的层数*/
void eval(struct ast*,int level);