#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "keys.c"
#include "files.c"
#include "syntax_check.c"

#ifndef MAX_SIZE_ARRAY
#define MAX_SIZE_ARRAY 65000    // Max file size to manage
#endif

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		puts("\n\tERROR: No se proporciono ruta."); // No file name was provided
		return(21);
	}

	char fileName[512] = "";
	char source[MAX_SIZE_ARRAY] = {0};      // Source code file
	char array[MAX_SIZE_ARRAY] = {0};       // Array to work with bytes
	char *ptr = array;                      // Pointer to the Array
	char car = 0;
	long i = 0;
	char output[MAX_SIZE_ARRAY] = {0};

	// Identify arguments
	strcpy(fileName, argv[1]);

	if (strlen(fileName) == 0)            
		puts("\n\tERROR: No se proporciono ruta."); // No file name was provided
	else
	{                                // File name was provided
		readFile(fileName, source);         // Truncate contents of source code file into array source

		if (strlen(source) != 0)
		{          // Array not empty
			int synCode = 0;
			synCode = syntax_check(source); // Store result of the syntax check

			if (synCode != 0)
			{             // Syntax error
				puts("\n\tERROR: Error de sintaxis.");

				if (synCode < 0)
				{          // Found single opening key
					printf("\t\tHay una llave sin cerrar en la posicion %d.\n\n", (-1 * synCode));
				}
				else
				{                    // Found single closing key
					printf("\t\tHay una llave sin abrir en la posicion %d.\n\n", synCode);
				}
			}
			else
			{                        // No error found
				// Iterate through the contents of the source code
				while (i < MAX_SIZE_ARRAY) {
					car = source[i];

					switch (car)
					{
						case '+':
							++*ptr;
							break;
						case '-':
							--*ptr;
							break;
						case '>':
							++ptr;
							break;
						case '<':
							--ptr;
							break;
						case ',':
							*ptr = getchar();
							break;
						case '.':
							output[strlen(output)] = *ptr;
							break;
						case '[':
							if (*ptr == 0)
								i = matching_closing_key(i, source);
								
							break;
						case ']':
							if (*ptr != 0)
								i = matching_opening_key(i, source);
								
							break;
					}

					i++;
				}

				putchar('\n');
				putchar('\n');

				printf("Resultado: %s\n", output);
			}
		}
		else
		{                            // No contents / file empty
			puts("\n\tERROR: No se pudo leer el archivo o no tenia contenidos.");
		}
	}

	return 1;
}
