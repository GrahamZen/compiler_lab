#ifndef LEX
    #include <stdio.h>
    #include "syn_tree.tab.h"
    extern int yyparse (void);
    extern int yylex (void);
#else
    #include "syn_tree.h"
    #include "token.h"
    void lexical_analysis() {
        int token;
        while (token = yylex()) {
            printoken(token);
            printf("%s)\n",yytext);
        }
    }
#endif // LEX


int main()
{
#ifndef LEX
    printf(">");
    return yyparse();
#else
    lexical_analysis();
#endif // LEX
}

