#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void _outOfMemCheck(char *buf)
{
    if (buf == NULL)
    {
        fprintf(stderr, "Failed to read file: out of memory\n");
        exit(EXIT_FAILURE);
    }
}

char *readFile(char *filename)
{
    FILE *fptr;

    fptr = fopen(filename, "rb");

    if (fptr == NULL)
    {
        fprintf(stderr, "File was not found\n");
        exit(EXIT_FAILURE);
    }

    fseek(fptr, 0L, SEEK_END);
    long length = ftell(fptr);
    rewind(fptr);

    char *contents = malloc(length * sizeof(char));

    _outOfMemCheck(contents);

    for (int i = 0; i < length; i++)
    {
        contents[i] = fgetc(fptr);
    }

    fclose(fptr);

    return contents;
}