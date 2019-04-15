#ifndef PRINT_INFO_C
#define PRINT_INFO_C

#include <stdio.h>
#include <unistd.h>

#include "fileSearch.h"

void printFreeMemory() {
	FILE *file = fopen("/proc/meminfo", "r");

	findPattern(file, "MemTotal:", 9);

	while (fgetc(file) == ' ') {}

	move(file, -1);

	double totalMemory = getInt(file, ' ');


 	findPattern(file, "MemFree:", 8);
 
 	while (fgetc(file) == ' ') {}

	move(file, -1);
 
 	double freeMemory = getInt(file, ' ');

 	printf("Free Memory:  %.5f%%\n", 100 * freeMemory / totalMemory);
 
 	fclose(file);
}

void printModeTime() {
	FILE *file;

	file = fopen("/proc/uptime", "r");

	double totalTime = getInt(file, '.');

	findChar(file, ' ');

	double idleTime = getInt(file, '.');

	fclose(file);



	file = fopen("/proc/stat", "r");

	findPattern(file, "cpu", 3);

	while (fgetc(file) == ' ') {}

	move(file, -1);

	double userTime = (float) getInt(file, ' ') / 100;

	getInt(file, ' ');

	double systemTime = (float) getInt(file, ' ') / 100;

	printf("User time:    %f%%\n", 100 * userTime / totalTime);
	printf("System time:  %f%%\n", 100 * systemTime / totalTime);
	printf("Idle time:    %f%%\n", 100 * idleTime / totalTime);

	fclose(file);
}

void setSwitches(int *contexts, int *processes) {
	FILE *file = fopen("/proc/stat", "r");

	findPattern(file, "ctxt", 4);

	fgetc(file);

	*contexts = getInt(file, '\n');

	findPattern(file, "processes", 9);

	fgetc(file);

	*processes = getInt(file, '\n');

	fclose(file);
}

void printSwitches() {
	float f = 0.0000001;

	int contextSwitches, pastContextSwitches;
	int processSwitches, pastProcessSwitches;

	setSwitches(&pastContextSwitches, &pastProcessSwitches);

	while (f < 1) {
		sleep(1);

		setSwitches(&contextSwitches, &processSwitches);

		printf(
			"Context change ratio:   %d changes/s    \n",
			contextSwitches - pastContextSwitches
		);

		printf(
			"Process creation ratio: %d creations/s    \n",
			processSwitches - pastProcessSwitches
		);

		printf("\r\033[2A");

		pastContextSwitches = contextSwitches;
		pastProcessSwitches = processSwitches;
	}
}
	

#endif
