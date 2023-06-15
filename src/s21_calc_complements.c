#include "s21_matrix.h"
#include "support.h"

// 0 - OK
// 1 - Ошибка, некорректная матрица
// 2 - Ошибка вычисления (несовпадающие размеры матриц; матрица, для которой
// нельзя провести вычисления и т.д.)

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int res = OK;

  if (checkMatrixForNull(A) && result) {
    if (A->rows == A->columns) {
      res = s21_create_matrix(A->rows, A->columns, result);
      if (A->rows == 1) {
        result->matrix[0][0] = A->matrix[0][0];
      } else {
        double determinant = 0;
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < A->rows; j++) {
            matrix_t tmp = {0};
            s21_create_matrix(A->rows - 1, A->columns - 1, &tmp);
            minorMatrix(A, &tmp, i, j);
            s21_determinant(&tmp, &determinant);
            result->matrix[i][j] = pow(-1, i + j) * determinant;
            s21_remove_matrix(&tmp);
          }
        }
      }
    } else {
      res = CALCULATION_ERROR;
    }
  } else {
    res = INCORRECT_MATRIX;
  }
  return res;
}