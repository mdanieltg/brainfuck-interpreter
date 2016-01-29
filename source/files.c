#include <stdio.h>
#include <string.h>

void readFile(const char* fileName, char contents[]) {
	FILE *file;
	file = fopen(fileName, "r");
	char buffer = 0;
	int i = 0;

    while ((buffer = fgetc(file)) != EOF) {
        if (i == 65000)
            break;

        contents[i] = buffer;
        i++;
    }

	return;
}
