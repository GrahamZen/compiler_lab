%{
#define YYSTYPE char *
#include "gramtree.tab.h"
#include "gramtree.h"
int cur_line_num = 1;
void lex_error(char* msg, int line);
#define _DUPTEXT {yylval = strdup(yytext);}

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

{OPERATOR}              { return yytext[0];         }   

"<="                    { return Le;              }
">="                    { return Ge;              }
":="                    { return Def;              }
"=="                    { return Eq;              }
"!="                    { return Ne;              }
"&&"                    { return And;             }
"||"                    { return Or;              }
"INT"                   { return Int;             }
"WHILE"                 { return While;           }
"IF"                    { return If;              }
"ELSE"                  { return Else;            }
"RETURN"                { return Return;          }
"WRITE"                 { return WRITE;           }
"READ"                  { return READ;         }
"BEGIN"                 { return BEGIN_KEY;         }
"END"               { return END_KEY;         }
"MAIN"                  { return MAIN;         }

{DIGIT}                 {_DUPTEXT; return IntConstant;     }
{NUMBER}                { _DUPTEXT;return Real;     }
{STRING}                { _DUPTEXT;return StringConstant;  }
{IDENTIFIER}            {  _DUPTEXT;return IDENTIFIER;      }

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
