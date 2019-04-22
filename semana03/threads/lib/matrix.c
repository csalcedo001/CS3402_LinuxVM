#ifndef MATRIX_C
#define MATRIX_C

#include <stdlib.h>

#include "matrix.h"

matrixContainer *initMatrix(int height, int width) {
	matrixContainer *M = (matrixContainer*) malloc(sizeof(matrixContainer));

	M->height = height;
	M->width = width;
	M->matrix = (int **) malloc(sizeof(int *) * height);

	for (int row = 0; row < height; ++row) {
		M->matrix[row] = (int *) malloc(sizeof(int) * width);
	}

	return M;
}

void randomFillMatrix(matrixContainer *M, int min, int max) {}

void deleteMatrix(matrixContainer *M) {
	for (int row = 0; row < M->height; ++row) {
		free(M->matrix[row]);
	}

	free(M->matrix);

	free(M);
}

#endif
