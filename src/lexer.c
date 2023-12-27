#include <stdio.h>
#include <stdlib.h>

#include "lexer.h"

void lex(CharArr *source, Token *out)
{
    while (source->array[0] != '\0')
    {
        // char *slay = source->array;
        char *slay = malloc(10 * sizeof(char));
        printf("%s\n", slay[0]);

        source->array++;
    }
}