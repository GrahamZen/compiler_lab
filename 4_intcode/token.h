#ifndef TOKEN_H
#define TOKEN_H
#include <string>
#include <stdio.h>
using std::string;

typedef enum
{
    Le = 256, Ge, Eq, Ne, Def, And, Or, IntConstant, REAL, RealConstant, StringConstant, Identifier, INT,
    WHILE, If, Else, Return, OP, BEGIN_KEY, END_KEY, DECLARE, MAIN, WRITE, READ
} TokenType;

string getTokenStr(int token)
{
    static char *token_strs[] = {
        "Le", "Ge", "Eq", "Ne", "Def", "And", "Or", "IntConstant", "REAL", "RealConstant", "StringConstant", "Identifier", "INT", "WHILE",
        "If", "Else", "Return", "OP", "BEGIN_KEY", "END_KEY", "DECLARE", "MAIN", "WRITE", "READ"};

    return token_strs[token-256];
}
static void printoken(int token)
{
    static char *token_strs[] = {
        "Le", "Ge", "Eq", "Ne", "Def", "And", "Or", "IntConstant", "REAL", "RealConstant", "StringConstant", "Identifier", "INT", "WHILE",
        "If", "Else", "Return", "OP", "BEGIN_KEY", "END_KEY", "DECLARE", "MAIN", "WRITE", "READ"};

    if (token < 256)
    {
        printf("(%c,", token);
    }
    else
    {
        printf("(%s,", token_strs[token - 256]);
    }
}

#endif