#include "syn_tree.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#define BUFFSIZE 40
void lexical_analysis();

struct AST *createASTNode(char *name, int num, ...)
{
    va_list valist;
    struct AST *root = (struct AST *)malloc(sizeof(struct AST));
    root->idName=NULL;
    root->leftNode=NULL;
    root->rightNode=NULL;
    //examine if alloc failed
    if (!root)
    {
        yyerror("RUN OUT OF MEMORY.");
        exit(0);
    }
    root->name = name;
    // init variable args
    va_start(valist, num);
    if (num > 0)
    {
        // get next argument
        struct AST *child = va_arg(valist, struct AST *);
        root->leftNode = child;
        // synthesize lineNo property from child
        root->lineNo = child->lineNo;
        if (num > 1)
        {
            for (int i = 0; i < num - 1; ++i)
            {
                // generate other branch as child for tree of same level(use binary tree to simulate tree of multiple branch)
                child->rightNode = va_arg(valist, struct AST *);
                child = child->rightNode;
            }
        }
    }
    else
    {
        int arg = va_arg(valist, int);
        root->lineNo = arg;
        /* 3 case of terminal:
        *   string
        *   int
        *   float
        */
        if (!strcmp(root->name, "Identifier") || !strcmp(root->name, "StringConstant"))
        {
            root->idName = (char *)malloc(sizeof(char) * BUFFSIZE);
            strcpy(root->idName, yytext);
        }
        else if (!strcmp(root->name, "IntConstant"))
            root->intVal = atoi(yytext);
        else if (!strcmp(root->name, "RealConstant"))
            root->floatVal = atof(yytext);
    }
    return root;
}

void traverse(struct AST *root, int level)
{
    if (!root)
        return;
    for (int i = 0; i < level; ++i)
        printf("\t");
    if (root->lineNo != -1)
    {
        printf("%s ", root->name);
        if ((!strcmp(root->name, "Identifier")))
            printf(":%s ", root->idName);
        else if (!strcmp(root->name, "StringConstant"))
            printf(":%s", root->idName);
        else if (!strcmp(root->name, "IntConstant"))
            printf(":%d", root->intVal);
        else if (!strcmp(root->name, "RealConstant"))
            printf(":%f", root->floatVal);
        else
            printf("(%d)", root->lineNo);
    }
    printf("\n");
    traverse(root->leftNode, level + 1);
    traverse(root->rightNode, level);
}
void destroy(struct AST *root){
    if(!root)return;
    if(root->leftNode)
        destroy(root->leftNode);
    if(root->rightNode)
        destroy(root->rightNode);
    if(root->idName)
        printf("%s\n",root->idName);
    free(root);
}


void yyerror(char *s) {
    fprintf(stderr, "line %d: %s\n", yylineno, s);
}
