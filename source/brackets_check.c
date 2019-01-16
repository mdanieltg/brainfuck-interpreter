/* Brainfuck Interpreter
 * Implementation in C of an interpreter for the Brainfuck language
 * Copyright (C) 2019  Daniel Medrano
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <string.h>
#include "brackets_check.h"
#include "brackets.h"

long brackets_check(const char* str)
{
    unsigned int length = strlen(str);

    // Check single-opening brackets
    for (long i = 0; i < length; i++)
        if (str[i] == '[')
            if (matching_closing_bracket(i, str) == -1)
                // Return non-zero based position, negative for single opening brackets
                return -1 * (i + 1);

    // Check single-closing brackets
    for (long i = 0; i < length; i++)
        if (str[i] == ']')
            if (matching_opening_bracket(i, str) == -1)
                // Return non-zero based position, positive for single closing brackets
                return i + 1;

    // Return zero for no errors found
    return 0;
}
