#include <stdio.h>
#include "token.h"

const char *token_strs[] = {
    "Le", "Ge", "Eq", "Ne", "Def", "And", "Or", "IntConstant", "REAL", "RealConstant", "StringConstant", "Identifier", "INT", "WHILE",
    "If", "Else", "Return", "OP", "BEGIN_KEY", "END_KEY", "DECLARE", "MAIN", "WRITE", "READ"};

static void printoken(int token)
{
    if (token < 256)
    {
        printf("(%c,", token);
    }
    else
    {
        printf("(%s,", token_strs[token - 256]);
    }
}
