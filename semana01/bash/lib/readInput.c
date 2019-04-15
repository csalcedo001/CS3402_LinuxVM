#ifndef READ_INPUT_C
#define READ_INPUT_C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "readInput.h"

// Read stdin, save in input, obtain list of arguments and return its length
int readInput(char input[], char *args[]) {
	int iIndex = 0, aIndex = 0;
	char state = ' ';

	char current = getchar();

	while (current != '\n' && iIndex < MAX_CHAR && aIndex < MAX_ARGS) {
		if (state == 's') {
			if (current != ' ') {
				input[iIndex] = current;
			}
			else {
				input[iIndex] = '\0';

				state = ' ';
			}

			++iIndex;
		} else if (state == ' ') {
			if (current != ' ') {
				args[aIndex++] = &(input[iIndex]);
				input[iIndex++] = current;

				state = current == '"' ? '"' : 's';
			}
		} else if (state == '"') {
			if (current != '"') {
				input[iIndex] = current;
			}
			else {
				input[iIndex] = '\0';

				state = ' ';
			}

			++iIndex;
		}

		current = getchar();
	}

	return aIndex;
}

#endif
