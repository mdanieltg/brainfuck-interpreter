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

#ifndef _BRACKETS_H
#define _BRACKETS_H

long matching_opening_bracket(const long at, const char* code);
long matching_closing_bracket(const long at, const char* code);

#endif // _BRACKETS_H
