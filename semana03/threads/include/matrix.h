#ifndef MATRIX_H
#define MATRIX_H

typedef int **matrix;

typedef struct matrixContainer {
	int height;
	int width;
	matrix matrix;
} matrixContainer;

matrixContainer *initMatrix(int, int);
void deleteMatrix(matrixContainer *);
void clearMatrix(matrixContainer *);
void randomFillMatrix(matrixContainer *);
void setMatrixRandomSeed(int);
void printMatrix(matrixContainer *);
void sequentialMatrixMultiplication(
	matrixContainer*,
	matrixContainer*,
	matrixContainer*
);
int getNextTask(int *, int *);
void *solveNextTask(void *);
void parallelMatrixMultiplication(
	matrixContainer*,
	matrixContainer*,
	matrixContainer*,
	int
);

#endif
