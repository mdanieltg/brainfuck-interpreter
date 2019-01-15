#include <stdio.h>
#include <string.h>
#include "files.h"
#include "keys.h"
#include "syntax_check.h"

#ifndef MAX_SIZE_ARRAY
#define MAX_SIZE_ARRAY 65000    // Max file size to manage
#endif

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        // No file name was provided
        printf("ERROR: No se proporcionó ruta.\n\n");
        return(21);
    }

    char filename[512] = { 0 };
    char source[MAX_SIZE_ARRAY] = { 0 };
    char workspace[MAX_SIZE_ARRAY] = { 0 };
    char output[MAX_SIZE_ARRAY] = { 0 };

    // Pointer to the Array
    char* ptr = workspace;

    // Identify arguments
    strcpy(filename, argv[1]);

    if (strlen(filename) == 0)
        // No file name was provided
        printf("ERROR: No se proporcionó ruta.\n\n");
    else
    {
        // File name was provided
        // Truncate contents of source code file into array source
        read_file(filename, source);

        if (strlen(source) != 0)
        {
            // Store result of the syntax check
            int syntax_check_result = syntax_check(source);

            if (syntax_check_result != 0)
            {
                // Syntax error
                printf("ERROR: Error de sintaxis.\n\n");

                if (syntax_check_result < 0)
                    // Found single opening key
                    printf(">Hay una llave sin cerrar en la posicion %d.\n\n",
                        (-1 * syntax_check_result));
                else
                    // Found single closing key
                    printf(">Hay una llave sin abrir en la posicion %d.\n\n",
                        syntax_check_result);
            }
            else
            {
                // No error found
                // Iterate through the contents of the source code
                for (long i = 0; i < MAX_SIZE_ARRAY; i++)
                {
                    char car = source[i];

                    if      (car == '+') ++*ptr;
                    else if (car == '-') --*ptr;
                    else if (car == '>') ++ptr;
                    else if (car == '<') --ptr;
                    else if (car == ',') *ptr = getchar();
                    else if (car == '.') output[strlen(output)] = *ptr;
                    else if (car == '[')
                    {
                        if (*ptr == 0)
                            i = matching_closing_key(i, source);
                    }
                    else if (car == ']')
                    {
                        if (*ptr != 0)
                            i = matching_opening_key(i, source);
                    }
                }

                printf("Resultado:\n");
                printf("%s\n", output);
            }
        }
        else
            // No contents / file empty
            printf("ERROR: No se pudo leer el archivo o no tenía contenidos.\n\n");
    }

    return 0;
}
