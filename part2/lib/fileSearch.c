#ifndef FILE_SEARCH_C
#define FILE_SEARCH_C

#include <stdio.h>
#include <stdlib.h>

#include "fileSearch.h"

void move(FILE *file, int steps) {
	fseek(file, steps, SEEK_CUR);
}

void findPattern(FILE *file, char s[], int size) {
	for (int index = 0; index < size; ++index) {
		if (s[index] != fgetc(file)) {
			index = -1;
		}
	}
}

int findChar(FILE *file, char c) {
	int length = 0;
	
	while (fgetc(file) != c) {
		++length;
	}

	return length;
}

void printLine(FILE *file) {
	char current;

	while ((current = fgetc(file)) != '\n') {
		printf("%c", current);
	}

	printf("\n");
}

int parseInt(FILE *file, int length) {
	char number[length];

	for (int index = 0; index < length; index++) {
		number[index] = fgetc(file);
	}

	return atoi(number);
}

int getInt(FILE *file, char stopChar) {
	int length = findChar(file, stopChar);

	move(file, -length - 1);
	
	int result = parseInt(file, length);

	move(file, 1);

	return result;
}

#endif
