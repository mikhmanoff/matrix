#include "s21_matrix.h"
#include "support.h"

// 0 - OK
// 1 - Ошибка, некорректная матрица
// 2 - Ошибка вычисления (несовпадающие размеры матриц; матрица, для которой
// нельзя провести вычисления и т.д.)

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int res = OK;

  if (checkMatrixForNull(A)) {
    res = s21_create_matrix(A->rows, A->columns, result);

    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
      }
    }
  } else {
    res = INCORRECT_MATRIX;
  }

  return res;
}