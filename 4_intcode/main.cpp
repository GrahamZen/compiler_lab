#include <stdio.h>
#include "syn_tree.tab.h"
extern int yyparse (void);
extern int yylex (void);



int main()
{
#ifndef LEX
    printf(">");
    return yyparse();
#else
    lexical_analysis();
#endif // LEX
}

