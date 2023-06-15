#ifndef SUPPORT_H
#define SUPPORT_H

#include "s21_matrix.h"

// support func

// 1 - OK
int checkMatrixForNull(matrix_t *A);
void minorMatrix(matrix_t *A, matrix_t *result, int row, int col);
double determinant(matrix_t *A);

#endif  // SUPPORT_H
