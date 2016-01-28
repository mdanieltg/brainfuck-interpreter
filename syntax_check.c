#include <string.h>
#include "keys.h"

long syntax_check(const char *str) {
    long i = 0;

    // Check single-opening brackets
    while (i < strlen(str)) {
        if (str[i] == '[')
            if (matching_closing_key(i, str) == -1)
                return (-1 * (i + 1));

        i++;
    }

    // Check single-closeing brackets
    i = 0;
    while (i < strlen(str)) {
        if (str[i] == ']')
            if (matching_opening_key(i, str) == -1)
                return (i + 1);

        i++;
    }

    // Negativos para apertura
    // Positivos para cierre
    // Cero para correcto
    return 0;
}
