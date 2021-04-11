%{
#include "gramtree.h"
#include "token.h"
int cur_line_num = 1;
void iniscanner();
void lex_error(char* msg, int line);
%}

/* Definitions, note: \042 is '"' */
DIGIT               ([0-9]+)
NUMBER              {DIGIT}.{DIGIT}
STRING              (\042[^\042\n]*\042)
BEGIN               BEGIN
END                 END
IDENTIFIER          ([_a-zA-Z][_a-zA-Z0-9]*)
OPERATOR            ([+*-/%=,;!<>(){}])
SINGLE_COMMENT1     ("//"[^\n]*)
SINGLE_COMMENT2     (\/\*\*.*?\*\*\/)

%%

[\n]                { cur_line_num++;                       }
[ \t\r\a]+          { /* ignore all spaces */               }
{SINGLE_COMMENT1}   { /* skip for single line comment */    }
{SINGLE_COMMENT2}   { /* skip for single line commnet */    }

{OPERATOR}          { yylval.a=newast("OP",0,yylineno);return OP;         }   

"<="                { yylval.a=newast("Le",0,yylineno);return Le;              }
">="                { yylval.a=newast("Ge",0,yylineno);return Ge;              }
":="                { yylval.a=newast("Def",0,yylineno);return Def;              }
"=="                { yylval.a=newast("Eq",0,yylineno);return Eq;              }
"!="                { yylval.a=newast("Ne",0,yylineno);return Ne;              }
"&&"                { yylval.a=newast("And",0,yylineno);return And;             }
"||"                { yylval.a=newast("Or",0,yylineno);return Or;              }
"void"              { yylval.a=newast("Void",0,yylineno);return Void;            }
"int"               { yylval.a=newast("Int",0,yylineno);return Int;             }
"while"             { yylval.a=newast("While",0,yylineno);return While;           }
"if"                { yylval.a=newast("If",0,yylineno);return If;              }
"else"              { yylval.a=newast("Else",0,yylineno);return Else;            }
"return"            { yylval.a=newast("Return",0,yylineno);return Return;          }
"break"             { yylval.a=newast("Break",0,yylineno);return Break;           }
"continue"          { yylval.a=newast("Continue",0,yylineno);return Continue;        }
"print"             { yylval.a=newast("Print",0,yylineno);return Print;           }
"readint"           { yylval.a=newast("ReadInt",0,yylineno);return ReadInt;         }

{DIGIT}           { yylval.a=newast("IntConstant",0,yylineno);return IntConstant;     }
{NUMBER}           { yylval.a=newast("Real",0,yylineno);return Real;     }
{STRING}            { yylval.a=newast("StringConstant",0,yylineno);return StringConstant;  }
{IDENTIFIER}        { yylval.a=newast("Identifier",0,yylineno);return Identifier;      }

<<EOF>>             { return 0; }

.                   { lex_error("Unrecognized character", cur_line_num);        }

%%

void lex_error(char* msg, int line) {
    printf("\nError at line %-3d: %s\n\n", line, msg);
}

int yywrap(void) {
    return 1;
}