#include <string.h>
#include "syntax_check.h"
#include "keys.h"

long syntax_check(const char* str)
{
    unsigned int length = strlen(str);

    // Check single-opening brackets
    for (long i = 0; i < length; i++)
        if (str[i] == '[')
            if (matching_closing_key(i, str) == -1)
                // Return non-zero based position, negative for single opening brackets
                return -1 * (i + 1);

    // Check single-closing brackets
    for (long i = 0; i < length; i++)
        if (str[i] == ']')
            if (matching_opening_key(i, str) == -1)
                // Return non-zero based position, positive for single closing brackets
                return i + 1;

    // Return zero for no errors found
    return 0;
}
