#ifndef TOKEN_H
#define TOKEN_H

typedef enum {
    Le = 256, Ge, Eq, Ne,Def, And, Or, IntConstant,Real,
    StringConstant, IDENTIFIER, Int, While,
    If, Else, Return, OP,BEGIN_KEY,END_KEY,DECLARE,MAIN,WRITE,READ
} TokenType;

static void printoken(int token) {
    static char* token_strs[] = {
        "Le", "Ge", "Eq", "Ne", "Def","And", "Or", "IntConstant","Real",
        "StringConstant", "IDENTIFIER",  "Int", "While",
        "If", "Else", "Return", "OP","BEGIN_KEY","END_KEY","DECLARE","MAIN","WRITE","READ"
    };

    if (token < 256) {
        printf("(%c,", token);
    } else {
        printf("(%s,", token_strs[token-256]);
    }
}

#endif