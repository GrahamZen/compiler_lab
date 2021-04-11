#ifndef TOKEN_H
#define TOKEN_H

typedef enum {
    Le = 256, Ge, Eq, Ne,Def, And, Or, IntConstant,Real,
    StringConstant, Identifier, Void, Int, While,
    If, Else, Return, Break, Continue, Print,
    ReadInt,OP
} TokenType;

static void printoken(int token) {
    static char* token_strs[] = {
        "Le", "Ge", "Eq", "Ne", "Def","And", "Or", "IntConstant","Real",
        "StringConstant", "Identifier", "Void", "Int", "While",
        "If", "Else", "Return", "Break", "Continue", "Print",
        "ReadInt","OP"
    };

    if (token < 256) {
        printf("(%c,", token);
    } else {
        printf("(%s,", token_strs[token-256]);
    }
}

#endif