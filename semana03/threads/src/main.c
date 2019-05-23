#include <stdio.h>
#include <sys/time.h>

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

	
	struct timeval start, end;

	gettimeofday(&start, NULL);
	sequentialMatrixMultiplication(A, B, C);
	gettimeofday(&end, NULL);

	long long sequentialTime = end.tv_usec - start.tv_usec + (end.tv_sec - start.tv_sec) * 1000000;


	clearMatrix(C);

	setMatrixRandomSeed(seed);

	randomFillMatrix(A);
	randomFillMatrix(B);

	gettimeofday(&start, NULL);
	parallelMatrixMultiplication(A, B, C, 8);
	gettimeofday(&end, NULL);

	long long parallelTime = end.tv_usec - start.tv_usec + (end.tv_sec - start.tv_sec) * 1000000;

	printf("\nTiempo secuencial: %lld\nTiempo paralelo: %lld\n", sequentialTime, parallelTime);

	deleteMatrix(A);
	deleteMatrix(B);
	deleteMatrix(C);
	
	return 0;
}
