#ifndef MATRIX_C
#define MATRIX_C

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "matrix.h"


matrixContainer *initMatrix(int height, int width) {
	matrixContainer *M = (matrixContainer*) malloc(sizeof(matrixContainer));

	M->height = height;
	M->width = width;
	M->matrix = (int **) malloc(sizeof(int *) * height);

	for (int row = 0; row < height; ++row) {
		M->matrix[row] = (int *) calloc(width, sizeof(int));
	}

	srand(time(NULL));

	return M;
}

void deleteMatrix(matrixContainer *M) {
	for (int row = 0; row < M->height; ++row) {
		free(M->matrix[row]);
	}

	free(M->matrix);

	free(M);
}

void randomFillMatrix(matrixContainer *M) {
	for (int row = 0; row < M->height; ++row) {
		for(int col = 0; col < M->width; ++col) {
			M->matrix[row][col] = rand() % 6;
		}
	}
}

void sequentialMatrixMultiplication(
	matrixContainer *left,
	matrixContainer *right,
	matrixContainer *result)
{
	for (int row = 0; row < result->height; ++row) {
		for (int col = 0; col < result->width; ++col) {
			for (int it = 0; it < left->width; ++it) {
				result->matrix[row][col] += left->matrix[row][it] * right->matrix[it][col];
			}
		}
	}
}

void printMatrix(matrixContainer *M) {
	for (int row = 0; row < M->height; ++row) {
		for (int col = 0; col < M->width; ++col) {
			printf("%d ", M->matrix[row][col]);
		}

		printf("\b\n");
	}
}


#endif
