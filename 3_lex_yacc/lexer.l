%{
#include "gramtree.h"
#include "gramtree.tab.h"
int cur_line_num = 1;
void lex_error(char* msg, int line);

%}
%option yylineno

/* Definitions, note: \042 is '"' */
DIGIT               ([0-9]+)
NUMBER              {DIGIT}.{DIGIT}
STRING              (\042[^\042\n]*\042)
OPERATOR            ([+*-/%=,;!<>(){}])
SINGLE_COMMENT1     ("//"[^\n]*)
SINGLE_COMMENT2     (\/\*\*.*?\*\*\/)
IDENTIFIER          ([_a-zA-Z][_a-zA-Z0-9]*)

%%

[\n]                { cur_line_num++;                       }
[ \t\r\a]+          { /* ignore all spaces */               }
{SINGLE_COMMENT1}   { /* skip for single line comment */    }
{SINGLE_COMMENT2}   { /* skip for single line commnet */    }

{OPERATOR}          { yylval.a=newast("OP",0,yylineno);return yytext[0];         }   

"<="                { yylval.a=newast("Le",0,yylineno);return Le;              }
">="                { yylval.a=newast("Ge",0,yylineno);return Ge;              }
":="                { yylval.a=newast("Def",0,yylineno);return Def;              }
"=="                { yylval.a=newast("Eq",0,yylineno);return Eq;              }
"!="                { yylval.a=newast("Ne",0,yylineno);return Ne;              }
"&&"                { yylval.a=newast("And",0,yylineno);return And;             }
"||"                { yylval.a=newast("Or",0,yylineno);return Or;              }
"INT"               { yylval.a=newast("Int",0,yylineno);return Int;             }
"WHILE"             { yylval.a=newast("While",0,yylineno);return While;           }
"IF"                { yylval.a=newast("If",0,yylineno);return If;              }
"ELSE"              { yylval.a=newast("Else",0,yylineno);return Else;            }
"RETURN"            { yylval.a=newast("Return",0,yylineno);return Return;          }
"WRITE"             { yylval.a=newast("WRITE",0,yylineno);return WRITE;           }
"READ"           { yylval.a=newast("READ",0,yylineno);return READ;         }
"BEGIN"           { yylval.a=newast("BEGIN",0,yylineno);return BEGIN_KEY;         }
"END"           { yylval.a=newast("END",0,yylineno);return END_KEY;         }
"MAIN"           { yylval.a=newast("END",0,yylineno);return MAIN;         }

{DIGIT}                 {yylval.a=newast("IntConstant",0,yylineno); return IntConstant;     }
{NUMBER}                { yylval.a=newast("Real",0,yylineno);return Real;     }
{STRING}                { yylval.a=newast("StringConstant",0,yylineno);return StringConstant;  }
{IDENTIFIER}            {  yylval.a=newast("IDENTIFIER",0,yylineno);return IDENTIFIER;      }

<<EOF>>             { return 0; }

.                   { lex_error("Unrecognized character", cur_line_num);        }

%%

void lex_error(char* msg, int line) {
    printf("\nError at line %-3d: %s\n\n", line, msg);
}

int yywrap(void) {
    return 1;
}

// int main(int argc, char* argv[]) {
//     int token;
//     while (token = yylex()) {
//         printoken(token);
//         printf("%s)\n",yytext);
//     }
//     return 0;
// }
