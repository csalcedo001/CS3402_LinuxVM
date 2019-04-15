#ifndef FILE_SEARCH_H
#define FILE_SEARCH_H

#include <stdio.h>

void move(FILE *file, int length);
void findPattern(FILE *file, char s[], int size);
int findChar(FILE *file, char c);
void printLine(FILE *file);
int parseInt(FILE *file, int length);
int getInt(FILE *file, char stopChar);

#endif
