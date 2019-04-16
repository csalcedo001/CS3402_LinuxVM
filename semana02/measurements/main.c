#include <stdio.h>
#include <unistd.h>
#include <time.h>

#define TESTS 1000

void minimumFunction() {}

int main (void) {
	float totalTime = 0;

	for (int i = 0; i < TESTS; ++i) {
		struct timespec start, end;
		clock_gettime(CLOCK_MONOTONIC_RAW, &start);
		minimumFunction();
		clock_gettime(CLOCK_MONOTONIC_RAW, &end);
		totalTime += end.tv_nsec - start.tv_nsec;
	}

	printf("%.2f ns\n", totalTime / TESTS);

	totalTime = 0;
		
	for (int i = 0; i < TESTS; ++i) {
		struct timespec start, end;
		clock_gettime(CLOCK_MONOTONIC_RAW, &start);
		getpid();
		clock_gettime(CLOCK_MONOTONIC_RAW, &end);
		totalTime += end.tv_nsec - start.tv_nsec;
	}

	printf("%.2f ns\n", totalTime / TESTS);

	for (int i = 0; i < TEST; ++i) {
		
	}
	
	return 0;
}
