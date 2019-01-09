#include <string.h>
#include "keys.h"

long matching_closing_key(const long at, const char* code)
{
    long open = 0;
    long closed = 0;
    long pos = 0;

    pos = at;

    while (pos < strlen(code))
    {
        switch (code[pos])
        {
            case '[':
                open++;
                break;
            case ']':
                closed++;
                break;
        }

        if (open == closed)
            return pos;

        pos++;
    }

    return -1;
}

long matching_opening_key(const long at, const char* code)
{
    long open = 0;
    long closed = 0;
    long pos = 0;

    pos = at;

    while (pos >= 0)
    {
        switch (code[pos])
        {
            case '[':
                open++;
                break;
            case ']':
                closed++;
                break;
        }

        if (open == closed)
            return pos;

        pos--;
    }

    return -1;
}
