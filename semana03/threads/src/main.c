#include <stdio.h>

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

	printf("%d\n", A->matrix[0][0]);

	randomFillMatrix(A);
	
	printf("%d\n", A->matrix[0][0]);

	deleteMatrix(A);
	deleteMatrix(B);
	deleteMatrix(C);
	
	return 0;
}
