#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "matrix.h"

int main (int argc, char **argv) {
	matrixContainer *A, *B;

	int height, width;

	if (argc > 2) {
		printf("Usage: ./sequential [square matrix size]\n");
		return 1;
	}

	if (argc == 1) {
		// Get left matrix height and width
		scanf("%d %d", &height, &width);
	}
	else {
		height = atoi(argv[1]);
		width = height;
	}

	A = initMatrix(height, width);
	
	if (argc == 1) {
		// Get right matrix height and width
		scanf("%d %d", &height, &width);
	}

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
	
	sequentialMatrixMultiplication(A, B, C);


	deleteMatrix(A);
	deleteMatrix(B);
	deleteMatrix(C);
	
	return 0;
}
