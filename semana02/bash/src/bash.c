#include <stdio.h>

#include "readInput.h"
#include "bashCommands.h"

int main (void) {
	printf("\033[2J\033[H");

	while (true) {
		char input[MAX_CHAR + 1] = {0};
		char *args[MAX_ARGS + 1] = {NULL};

		char route[100];
		getcwd(route, 100);

		printf("SOcsalcedo:%s$ ", route);

		// Length of argument list
		int argl = readInput(input, args);

		pid_t pid;

		void (*command) (int, char**);

		if (argl) {
			if (!strcmp(args[0], "ls")) {
				command = &bash_ls;
			}
			else if (!strcmp(args[0], "cd")) {
				command = &bash_cd;
			}
			else if (!strcmp(args[0], "pwd")) {
				command = &bash_pwd;
			}
			else if (!strcmp(args[0], "mkdir")) {
				command = &bash_mkdir;
			}
			else if (!strcmp(args[0], "exit")) {
				command = &bash_exit;
			}
			else if (!strcmp(args[0], "rm")) {
				command = &bash_rm;
			}
			else if (!strcmp(args[0], "nano")) {
				command = &bash_nano;
			}
			else if (!strcmp(args[0], "cat")) {
				command = &bash_cat;
			}
			else {
				printf("%s: command not found\n", args[0]);
				continue;
			}

			command(argl, args);
		}
	}
	
	return 0;
}
