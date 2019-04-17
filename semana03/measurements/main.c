#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#define TESTS 20

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
	
	totalTime = 0;

	for (int i = 0; i < TESTS; ++i) {
		char write_msg = '\n';
		char read_msg;
		int fd[2];
		pid_t pid;

		struct timespec start, end;
	
		if (pipe(fd) == -1) {
			fprintf(stderr, "Pipe failed");
			return 1;
		}
	
		pid = fork();
	
		if (pid < 0) {
			fprintf(stderr, "Fork failed");
			return 1;
		}
		else if (pid > 0) {
			close(fd[0]);
	
			clock_gettime(CLOCK_MONOTONIC_RAW, &start);
			write(fd[1], &write_msg, 1);
	
			close(fd[1]);
			
			wait(NULL);

			clock_gettime(CLOCK_MONOTONIC_RAW, &end);

			totalTime += end.tv_nsec - start.tv_nsec;
		}
		else {
			close(fd[1]);
	
			read(fd[0], &read_msg, 1);
	
			close(fd[0]);

			exit(0);
		}
	}

	printf("%.2f ns\n", totalTime / TESTS);
	
	return 0;
}
