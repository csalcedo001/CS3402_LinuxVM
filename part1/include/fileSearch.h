#ifndef FILE_SEARCH_H
#define FILE_SEARCH_H

#include <stdio.h>

void step(FILE *file);

void findPattern(FILE *file, char s[], int size);

void findChar(FILE *file, char c);

void printLine(FILE *file);

#endif
