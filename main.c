#include <stdio.h>
#include <string.h>
#include "keys.h"

#define MAX_SIZE_ARRAY 65000

long syntax_check(const char*);
void readFile(const char*, char[]);

int main() {
	char fileName[512] = "";
	char source[MAX_SIZE_ARRAY] = {0};
	char array[MAX_SIZE_ARRAY] = {0};
	char *ptr = array;
	char car = 0;
	long i = 0;
	char output[MAX_SIZE_ARRAY] = {0};

    printf("ATENCION: Solo se soportan archivos de menos de 65000 bytes.\n");
    printf("Ruta del archivo de codigo fuente: ");
    gets(fileName);

    if (strlen(fileName) == 0) {
        puts("\n\tERROR: No se proporciono ruta.");
    } else {
        readFile(fileName, source);

        if (strlen(source) != 0) {
            int synCode = 0;
            synCode = syntax_check(source);

            if (synCode != 0) {
                puts("\n\tERROR: Error de sintaxis.");

                if (synCode < 0) {
                    printf("\t\tHay una llave sin cerrar en la posicion %d.\n\n", (-1 * synCode));
                } else {
                    printf("\t\tHay una llave sin abrir en la posicion %d.\n\n", synCode);
                }
            } else {
                while (i < MAX_SIZE_ARRAY) {
                    car = source[i];

                    switch (car) {
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
                            if (*ptr == 0) {
                                i = matching_closing_key(i, source);
                            }

                            break;
                        case ']':
                            if (*ptr != 0) {
                                i = matching_opening_key(i, source);
                            }

                            break;
                    }

                    i++;
                }

                putchar('\n');
                putchar('\n');

                printf("Resultado: %s\n", output);
            }
        } else {
            puts("\n\tERROR: No se pudo leer el archivo o no tenia contenidos.");
        }
    }

    return 0;
}

long matching_closing_key(const long at, const char* code) {
    long open = 0;
    long closed = 0;
    long pos = 0;

    pos = at;

    while (pos < strlen(code)) {
        switch (code[pos]) {
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

long matching_opening_key(const long at, const char* code) {
    long open = 0;
    long closed = 0;
    long pos = 0;

    pos = at;

    while (pos >= 0) {
        switch (code[pos]) {
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
