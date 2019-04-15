#ifndef BASH_COMMANDS_H
#define BASH_COMMANDS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

#define FILE_NAME_LENGTH 256

void bash_ls(int, char **);
void bash_cd(int, char **);
void bash_mkdir(int, char **);
void bash_pwd(int, char **);
void bash_rm(int, char **);
void bash_exit(int, char**);
void bash_nano(int, char **);
void bash_cat(int, char **);

#endif
