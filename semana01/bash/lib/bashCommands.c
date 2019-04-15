#ifndef BASH_COMMANDS_C
#define BASH_COMMANDS_C

#include "bashCommands.h"

void bash_ls(int argl, char **args) {
	if (argl == 1) {
		DIR *dir;
		struct dirent *reader;
	
		char path[FILE_NAME_LENGTH + 1] = {0};
	
		getcwd(path, FILE_NAME_LENGTH);
	
		dir = opendir(path);
	
		while ((reader = readdir(dir)) != NULL) {
			if (reader->d_name[0] != '.') {
				printf("%s\t", reader->d_name);
			}
		}
	
		printf("\b\n");
	}
	else {
		printf("ls: unsupported number of operands\n");
	}
}
	
void bash_cd(int argl, char **args) {
	if (argl == 1) {
		chdir(getenv("HOME"));
	}
	else if (argl == 2) {
		chdir(args[1]);
	}
	else {
		printf("cd: too many arguments\n");
	}
}
void bash_mkdir(int argl, char **args) {
	if (argl > 1) {
		for (int i = 1; i < argl; i++) {
			mkdir(args[i], 00744);
		}
	}
	else {
		printf("mkdir: missing operands\n");
	}
}
void bash_pwd(int argl, char **args) {
	char path[FILE_NAME_LENGTH] = {'\0'};
	
	getcwd(path, FILE_NAME_LENGTH);

	printf("%s\n", path);
}
void bash_rm(int argl, char **args) {
	if (argl > 1) {
		for (int i = 1; i < argl; i++) {
			if (args[i][0] == '/') {
				unlink(args[i]);
			}
			else {
				char s[FILE_NAME_LENGTH + 1] = {'\0'};
				getcwd(s, FILE_NAME_LENGTH);
				strcat(s, "/");
				strcat(s, args[i]);
	
				unlink(s);
			}
		}
	}
	else {
		printf("rm: missing operands\n");
	}
}
void bash_exit(int argl, char **args) {
	exit(0);
}

void bash_nano(int argl, char **args) {
	pid_t pid;
	pid = fork();
	
	if (pid == 0) {
		execvp("nano", args);
	}
	else if (pid > 0) {
		wait(NULL);
	}
}

void bash_cat(int argl, char **args) {
	pid_t pid;
	pid = fork();
	
	if (pid == 0) {
		execvp("cat", args);
	}
	else if (pid > 0) {
		wait(NULL);
	}
}

#endif
