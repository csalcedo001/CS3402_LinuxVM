#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#include "matrix.h"

#define MAX_THREADS	20

int main (int argc, char **argv) {
	matrixContainer *A, *B;

	if (argc != 5) {
		printf("Usage: ./sequential [lHeight] [lWidth] [rHeight] [lWidth]\n");
		return 1;
	}

	A = initMatrix(atoi(argv[1]), atoi(argv[2]));
	
	B = initMatrix(atoi(argv[3]), atoi(argv[4]));

	// Check if matrix multiplication is posible
	if (A->width != B->height) {
		fprintf(stderr, "Failed: Unable to match matrix dimensions\n");

		deleteMatrix(A);
		deleteMatrix(B);

		return 1;
	}

	matrixContainer *C = initMatrix(A->height, B->width);

	clearMatrix(C);

	int seed = time(NULL);

	setMatrixRandomSeed(seed);

	randomFillMatrix(A);
	randomFillMatrix(B);
	
	for (int i = 1; i < MAX_THREADS; i++) {
		struct timeval startTime, endTime;

		gettimeofday(&startTime, NULL);
		parallelMatrixMultiplication(A, B, C, i);
		gettimeofday(&endTime, NULL);

		long long time = endTime.tv_usec - startTime.tv_usec;

		time += 1000000 * (endTime.tv_sec - startTime.tv_sec);

		printf("%lld, ", time);
	}

	printf("\n");

	deleteMatrix(A);
	deleteMatrix(B);
	deleteMatrix(C);
	
	return 0;
}
