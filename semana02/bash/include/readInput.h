#ifndef READ_INPUT_H
#define READ_INPUT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CHAR 1024
#define MAX_ARGS 128

// Read stdin, save in input, obtain list of arguments and return its length
int readInput(char input[], char *args[]);

#endif
