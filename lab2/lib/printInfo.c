#ifndef PRINT_INFO_C
#define PRINT_INFO_C

#include "fileSearch.h"

void printFreeMemory() {
	FILE *file = fopen("/proc/meminfo", "r");

	findPattern(file, "MemTotal:", 9);

	while (fgetc(file) == ' ') {}

	move(file, -1);

	int length = findChar(file, ' ');

	move(file, -length - 1);

	double totalMemory = parseInt(file, length);



 	findPattern(file, "MemFree:", 8);
 
 	while (fgetc(file) == ' ') {}

	move(file, -1);
 
 	length = findChar(file, ' ');
 
 	move(file, -length - 1);
 
 	double freeMemory = parseInt(file, length);

 	printf("Free Memory: %.5f%%\n", 100 * freeMemory / totalMemory);
 
 	fclose(file);
}

void printModeTime() {
	
}

#endif
