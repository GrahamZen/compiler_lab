#include <string.h>  

extern int yylineno;
extern char* yytext;
void yyerror(char *s);

struct AST
{
    int lineNo; 
    char* name;
    struct AST *leftNode;
    struct AST *rightNode;
    union
    {
        char* idName;
        int intVal;
        float floatVal;
    };
};

struct AST *createASTNode(char* name,int num,...);
void traverse(struct AST*,int level);