%{
#include "translator.h"
#include "syn_tree.tab.h"
int cur_line_num = 1;
void lex_error(char* msg, int line);
extern std::string tmpIdName;

%}
%option yylineno

POSITIVE            ([0-9]+)
INT                 [+-]?{POSITIVE}
REAL                {INT}.{POSITIVE}
STRING              (\042[^\042\n]*\042)
OPERATOR            ([+*-/%=,;!<>(){}])
SINGLE_COMMENT1     ("//"[^\n]*)
SINGLE_COMMENT2     (\/\*(?:[^\*]|\*+[^\/\*])*\*+\/)
Identifier          ([_a-zA-Z][_a-zA-Z0-9]*)

%%

[\n]                { cur_line_num++;                                                           }
[ \t\r\a]+          { /* ignore all spaces */                                                   }
{SINGLE_COMMENT1}   { /* skip for single line comment */                                        }
{SINGLE_COMMENT2}   { /* skip for single line commnet */                                        }

{OPERATOR}          { yylval.a=createNode("OP",yylineno);return yytext[0];                 }   

"<="                { yylval.a=createNode("Le",yylineno);return Le;                        }
">="                { yylval.a=createNode("Ge",yylineno);return Ge;                        }
":="                { yylval.a=createNode("Def",yylineno);return Def;                      }
"=="                { yylval.a=createNode("Eq",yylineno);return Eq;                        }
"!="                { yylval.a=createNode("Ne",yylineno);return Ne;                        }
"&&"                { yylval.a=createNode("And",yylineno);return And;                      }
"||"                { yylval.a=createNode("Or",yylineno);return Or;                        }
"INT"               { yylval.a=createNode("INT",yylineno);return INT;                      }
"REAL"              { yylval.a=createNode("REAL",yylineno);return REAL;                    }
"WHILE"             { yylval.a=createNode("WHILE",yylineno);return WHILE;                  }
"IF"                { yylval.a=createNode("If",yylineno);return If;                        }
"ELSE"              { yylval.a=createNode("Else",yylineno);return Else;                    }
"RETURN"            { yylval.a=createNode("Return",yylineno);return Return;                }
"WRITE"             { yylval.a=createNode("WRITE",yylineno);return WRITE;                  }
"READ"              { yylval.a=createNode("READ",yylineno);return READ;                    }
"BEGIN"             { yylval.a=createNode("BEGIN",yylineno);return BEGIN_KEY;              }
"END"               { yylval.a=createNode("END",yylineno);return END_KEY;                  }
"MAIN"              { yylval.a=createNode("MAIN",yylineno);return MAIN;                    }
{INT}               { yylval.a=createNode("IntConstant",yylineno); return IntConstant;     }
{REAL}              { yylval.a=createNode("RealConstant",yylineno);return RealConstant;    }
{STRING}            { yylval.a=createNode("StringConstant",yylineno);return StringConstant;}
{Identifier}        { yylval.a=createNode("Identifier",yylineno);tmpIdName=string(yytext);return Identifier;        }

<<EOF>>             { return 0;                                                                 }

.                   { lex_error("Unrecognized content", cur_line_num);                          }

%%

void lex_error(char* msg, int line) {
    printf("\nError at line %-3d: %s\n\n", line, msg);
}

int yywrap(void) {
    return 1;
}