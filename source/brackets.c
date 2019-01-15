#include <string.h>
#include "brackets.h"

long matching_opening_bracket(const long at, const char* code)
{
    long open = 0, closed = 0;

    for (long pos = at; pos >= 0; pos--)
    {
        if (code[pos] == '[')
            open++;
        else if (code[pos] == ']')
            closed++;

        if (open == closed)
            return pos;
    }

    return -1;
}

long matching_closing_bracket(const long at, const char* code)
{
    unsigned int length = strlen(code);
    long open = 0, closed = 0;

    for (long pos = at; pos < length; pos++)
    {
        if (code[pos] == '[')
            open++;
        else if (code[pos] == ']')
            closed++;

        if (open == closed)
            return pos;
    }

    return -1;
}
