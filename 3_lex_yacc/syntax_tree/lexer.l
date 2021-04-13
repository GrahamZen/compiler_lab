%{
#include "syn_tree.h"
#include "syn_tree.tab.h"
int cur_line_num = 1;
void lex_error(char* msg, int line);
%}
%option yylineno

POSITIVE            ([0-9]+)
INT                 [+-]?{POSITIVE}
REAL                {INT}.{POSITIVE}
STRING              (\042[^\042\n]*\042)
OPERATOR            ([+*-/%=,;!<>(){}])
SINGLE_COMMENT1     ("//"[^\n]*)
SINGLE_COMMENT2     (\/\*\*.*?\*\*\/)
Identifier          ([_a-zA-Z][_a-zA-Z0-9]*)

%%

[\n]                { cur_line_num++;                                                           }
[ \t\r\a]+          { /* ignore all spaces */                                                   }
{SINGLE_COMMENT1}   { /* skip for single line comment */                                        }
{SINGLE_COMMENT2}   { /* skip for single line commnet */                                        }

{OPERATOR}          { yylval.a=createASTNode("OP",0,yylineno);return yytext[0];                 }   

"<="                { yylval.a=createASTNode("Le",0,yylineno);return Le;                        }
">="                { yylval.a=createASTNode("Ge",0,yylineno);return Ge;                        }
":="                { yylval.a=createASTNode("Def",0,yylineno);return Def;                      }
"=="                { yylval.a=createASTNode("Eq",0,yylineno);return Eq;                        }
"!="                { yylval.a=createASTNode("Ne",0,yylineno);return Ne;                        }
"&&"                { yylval.a=createASTNode("And",0,yylineno);return And;                      }
"||"                { yylval.a=createASTNode("Or",0,yylineno);return Or;                        }
"INT"               { yylval.a=createASTNode("INT",0,yylineno);return INT;                      }
"REAL"              { yylval.a=createASTNode("REAL",0,yylineno);return REAL;                    }
"WHILE"             { yylval.a=createASTNode("WHILE",0,yylineno);return WHILE;                  }
"IF"                { yylval.a=createASTNode("If",0,yylineno);return If;                        }
"ELSE"              { yylval.a=createASTNode("Else",0,yylineno);return Else;                    }
"RETURN"            { yylval.a=createASTNode("Return",0,yylineno);return Return;                }
"WRITE"             { yylval.a=createASTNode("WRITE",0,yylineno);return WRITE;                  }
"READ"              { yylval.a=createASTNode("READ",0,yylineno);return READ;                    }
"BEGIN"             { yylval.a=createASTNode("BEGIN",0,yylineno);return BEGIN_KEY;              }
"END"               { yylval.a=createASTNode("END",0,yylineno);return END_KEY;                  }
"MAIN"              { yylval.a=createASTNode("MAIN",0,yylineno);return MAIN;                     }
{INT}             { yylval.a=createASTNode("IntConstant",0,yylineno); return IntConstant;     }
{REAL}            { yylval.a=createASTNode("RealConstant",0,yylineno);return RealConstant;    }
{STRING}            { yylval.a=createASTNode("StringConstant",0,yylineno);return StringConstant;}
{Identifier}        { yylval.a=createASTNode("Identifier",0,yylineno);return Identifier;        }

<<EOF>>             { return 0;                                                                 }

.                   { lex_error("Unrecognized content", cur_line_num);                        }

%%

void lex_error(char* msg, int line) {
    printf("\nError at line %-3d: %s\n\n", line, msg);
}

int yywrap(void) {
    return 1;
}