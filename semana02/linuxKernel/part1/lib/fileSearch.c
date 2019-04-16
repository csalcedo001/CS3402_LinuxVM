#ifndef FILE_SEARCH_C
#define FILE_SEARCH_C

#include <stdio.h>

void step(FILE *file) {
	fgetc(file);
}

void findPattern(FILE *file, char s[], int size) {
	for (int index = 0; index < size; ++index) {
		if (s[index] != fgetc(file)) {
			index = -1;
		}
	}
}

void findChar(FILE *file, char c) {
	while (fgetc(file) != c) {}
}

void printLine(FILE *file) {
	char current;

	while ((current = fgetc(file)) != '\n') {
		printf("%c", current);
	}

	printf("\n");
}

#endif
