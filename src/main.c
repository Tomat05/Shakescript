#include <stdlib.h>
#include <stdio.h>

#include "tools.h"
#include "input.h"
#include "lexer.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Invalid number of arguments entered, please enter just the name of the file to lex\n");
        exit(EXIT_FAILURE);
    }
    CharArr source;
    readFile(argv[1], &source);

    Token tokens[source.length];
    lex(&source, &tokens);
    // Token *tokens = lex(&source);
    // printf("%s", tokens->value);
    return 0;
}