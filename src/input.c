#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "input.h"

void _outOfMemCheck(char *buf)
{
    if (buf == NULL)
    {
        fprintf(stderr, "Failed to read file: out of memory\n");
        exit(EXIT_FAILURE);
    }
}

void readFile(char *filename, CharArr *out)
{
    FILE *fptr = fopen(filename, "rb");

    if (fptr == NULL)
    {
        fprintf(stderr, "File was not found\n");
        exit(EXIT_FAILURE);
    }

    fseek(fptr, 0L, SEEK_END);
    out->length = ftell(fptr);
    rewind(fptr);

    out->array = malloc(out->length * sizeof(char));

    _outOfMemCheck(out->array);

    for (int i = 0; i < out->length; i++)
    {
        out->array[i] = fgetc(fptr);
    }

    if (out->array[out->length - 1] != '\0')
    {
        out->array = realloc(out->array, (out->length + 1) * sizeof(char));
        out->array[out->length] = '\0';
    }

    fclose(fptr);
}