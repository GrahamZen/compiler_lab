%{
#include "translator.h"
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
SINGLE_COMMENT2     (\/\*(?:[^\*]|\*+[^\/\*])*\*+\/)
Identifier          ([_a-zA-Z][_a-zA-Z0-9]*)

%%

[\n]                { cur_line_num++;                                                           }
[ \t\r\a]+          { /* ignore all spaces */                                                   }
{SINGLE_COMMENT1}   { /* skip for single line comment */                                        }
{SINGLE_COMMENT2}   { /* skip for single line commnet */                                        }

{OPERATOR}          { return yytext[0];                 }   

"<="                { return Le;                        }
">="                { return Ge;                        }
":="                { return Def;                      }
"=="                { return Eq;                        }
"!="                { return Ne;                        }
"&&"                { return And;                      }
"||"                { return Or;                        }
"INT"               { return INT;                      }
"REAL"              { return REAL;                    }
"WHILE"             { return WHILE;                  }
"IF"                { return If;                        }
"ELSE"              { return Else;                    }
"RETURN"            { return Return;                }
"WRITE"             { return WRITE;                  }
"READ"              { return READ;                    }
"BEGIN"             { return BEGIN_KEY;              }
"END"               { return END_KEY;                  }
"MAIN"              { return MAIN;                    }
{INT}               {  return IntConstant;     }
{REAL}              { return RealConstant;    }
{STRING}            { return StringConstant;}
{Identifier}        { return Identifier;        }

<<EOF>>             { return 0;                                                                 }

.                   { lex_error("Unrecognized content", cur_line_num);                          }

%%

void lex_error(char* msg, int line) {
    printf("\nError at line %-3d: %s\n\n", line, msg);
}

int yywrap(void) {
    return 1;
}