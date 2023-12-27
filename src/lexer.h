#include "tools.h"

typedef enum TokenType
{
    BinExpr,
    Identifier,
} TokenType;

typedef struct Token
{
    TokenType type;
    char *value;
} Token;

void lex(CharArr *source, Token *out);