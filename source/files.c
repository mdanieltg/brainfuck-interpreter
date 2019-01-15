#include <stdio.h>
#include "files.h"

int read_file(const char* filename, char contents[])
{
    char buffer;
    int i = 0;

    FILE* file = fopen(filename, "r");
    if (file == NULL)
        return 1;

    while ((buffer = fgetc(file)) != EOF &&
        i <= 65000)
        if (buffer == '+' || buffer == '-' ||
            buffer == '>' || buffer == '<' ||
            buffer == ',' || buffer == '.' ||
            buffer == '[' || buffer == '[')
            contents[i++] = buffer;

    fclose(file);

    return 0;
}
