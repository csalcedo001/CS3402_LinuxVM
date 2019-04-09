#ifndef PRINT_INFO_C
#define PRINT_INFO_C

#include "fileSearch.h"

void printCPUName() {
	FILE *file = fopen("/proc/cpuinfo", "r");

	findPattern(file, "model name", 10);
	findChar(file, ':');
	fgetc(file);
	printLine(file);
	
	fclose(file);
}

void printMemory() {
	FILE *file = fopen("/proc/meminfo", "r");
	
	findPattern(file, "MemTotal", 8);

	fgetc(file);

	while (fgetc(file) == ' ') {}

	fseek(file, -1, SEEK_CUR);

	printLine(file);

	fclose(file);
}

void printKernelVersion() {
	FILE *file = fopen("/proc/version", "r");

	printLine(file);

	fclose(file);
}

void printUpTime() {
	FILE *file = fopen("/proc/stat", "r");

	findPattern(file, "btime", 5);

	fgetc(file);

	printLine(file);

	fclose(file);
}

#endif
