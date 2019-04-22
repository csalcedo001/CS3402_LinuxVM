#ifndef MATRIX_H
#define MATRIX_H

typedef int **matrix;

typedef struct matrixContainer {
	int height;
	int width;
	matrix matrix;
} matrixContainer;

matrixContainer *initMatrix(int, int);
void randomFillMatrix(matrixContainer *);
void deleteMatrix(matrixContainer *);

#endif
