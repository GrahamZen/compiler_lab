#ifndef TOKEN_H
#define TOKEN_H
#include <string>
using std::string;
typedef enum
{
    Le = 256, Ge, Eq, Ne, Def, And, Or, IntConstant, REAL, RealConstant, StringConstant, Identifier, INT,
    WHILE, If, Else, Return, OP, BEGIN_KEY, END_KEY, DECLARE, MAIN, WRITE, READ
} TokenType;
string getTokenStr(int token);


static void printoken(int token);


#endif