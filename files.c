#include <stdio.h>
#include <conio.h>

int readFile(const char* fileName, char contents[]) {
	FILE *file;
	file = fopen(fileName, "r");

	fgets(contents, 256, file);

	return 0;
}
