#include "s21_matrix.h"
#include "support.h"

// 0 - OK
// 1 - Ошибка, некорректная матрица
// 2 - Ошибка вычисления (несовпадающие размеры матриц; матрица, для которой
// нельзя провести вычисления и т.д.)

int s21_determinant(matrix_t *A, double *result) {
  int res = OK;

  if (checkMatrixForNull(A)) {
    if (A->columns == A->rows) {
      *result = determinant(A);
    } else {
      res = INCORRECT_MATRIX;
    }
  } else {
    res = CALCULATION_ERROR;
  }

  return res;
}