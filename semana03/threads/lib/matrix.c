#ifndef MATRIX_C
#define MATRIX_C

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <pthread.h>

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

void deleteMatrix(matrixContainer *M) {
	for (int row = 0; row < M->height; ++row) {
		free(M->matrix[row]);
	}

	free(M->matrix);

	free(M);
}

void clearMatrix(matrixContainer *M) {
	for (int row = 0; row < M->height; ++row) {
		memset(M->matrix[row], 0, sizeof(int) * M->width);
	}
}

void randomFillMatrix(matrixContainer *M) {
	for (int row = 0; row < M->height; ++row) {
		for(int col = 0; col < M->width; ++col) {
			M->matrix[row][col] = rand() % 6;
		}
	}
}

void setMatrixRandomSeed(int seed) {
	srand(seed);
}

void printMatrix(matrixContainer *M) {
	for (int row = 0; row < M->height; ++row) {
		for (int col = 0; col < M->width; ++col) {
			printf("%d ", M->matrix[row][col]);
		}

		printf("\b\n");
	}
}

void sequentialMatrixMultiplication(
	matrixContainer *left,
	matrixContainer *right,
	matrixContainer *result
) {
	for (int row = 0; row < result->height; ++row) {
		for (int col = 0; col < result->width; ++col) {
			for (int it = 0; it < left->width; ++it) {
				result->matrix[row][col] += left->matrix[row][it] * right->matrix[it][col];
			}
		}
	}
}

pthread_mutex_t lock;

matrixContainer *lM, *rM, *resultM;
int resultCol, resultRow;

// Assigns task variables row and column. Returns 1 if the task can be completed.
int getNextTask(int *row, int *col) {
	pthread_mutex_lock(&lock);

	if (resultRow < resultM->height) {
		*row = resultRow;
		*col = resultCol++;

		if (resultCol >= resultM->width) {
			resultCol = 0;
			resultRow++;
		}
		
		pthread_mutex_unlock(&lock);

		return 1;
	}

	pthread_mutex_unlock(&lock);

	return 0;
}

int t = 0;

// Calculates next available cell 
void *solveNextTask(void *data) {
	int c = t++;
	int row, col;

	while (getNextTask(&row, &col)) {
		for (int k = 0; k < lM->width; ++k) {
			resultM->matrix[row][col] += lM->matrix[row][k] * rM->matrix[k][col];
		}
	}

	return NULL;
}

void parallelMatrixMultiplication(
	matrixContainer *left,
	matrixContainer *right,
	matrixContainer *result,
	int threadNum
) {
	lM = left;
	rM = right;
	resultM = result;

	resultCol = resultRow = 0;


	pthread_t threads[threadNum];

	int threadIndex;

	for (threadIndex = 0; threadIndex < threadNum; ++threadIndex) {
		pthread_create(&threads[threadIndex], NULL, solveNextTask, NULL);
	}

	for (int i = 0; i < threadNum; ++i) {
		pthread_join(threads[i], NULL);
	}
}

#endif
