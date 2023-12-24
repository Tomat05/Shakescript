#include <stdlib.h>
#include <stdio.h>

#include "input.h"

int main(int argc, char *argv[])
{
    char *contents = readFile(argv[1]);
    printf("%s", contents);
    return 0;
}