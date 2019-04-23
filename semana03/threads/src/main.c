#include <stdio.h>
#include <time.h>

#include "matrix.h"

int main (void) {
	matrixContainer *A, *B;

	printf("Matrix multiplication: A x B \n");

	int height, width;

	printf("A dimensions (rows, columns): ");
	scanf("%d %d", &height, &width);

	A = initMatrix(height, width);
	
	printf("B dimensions (rows, columns): ");
	scanf("%d %d", &height, &width);

	B = initMatrix(height, width);

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

	
	struct timespec start, end;

	clock_gettime(CLOCK_MONOTONIC_RAW, &start);
	sequentialMatrixMultiplication(A, B, C);
	clock_gettime(CLOCK_MONOTONIC_RAW, &end); 
	long long sequentialTime = (long long) end.tv_nsec - start.tv_nsec;



	clearMatrix(C);

	setMatrixRandomSeed(seed);

	randomFillMatrix(A);
	randomFillMatrix(B);

	clock_gettime(CLOCK_MONOTONIC_RAW, &start);
	parallelMatrixMultiplication(A, B, C, 8);
	clock_gettime(CLOCK_MONOTONIC_RAW, &end);

	long long parallelTime = (long long) end.tv_nsec - start.tv_nsec;

	printf("\nTiempo secuencial: %lld\nTiempo paralelo: %lld\n", sequentialTime, parallelTime);

	deleteMatrix(A);
	deleteMatrix(B);
	deleteMatrix(C);
	
	return 0;
}
