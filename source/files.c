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
        contents[i++] = buffer;

    fclose(file);

    return 0;
}
