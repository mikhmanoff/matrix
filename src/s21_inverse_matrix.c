#include "s21_matrix.h"
#include "support.h"

// 0 - OK
// 1 - Ошибка, некорректная матрица
// 2 - Ошибка вычисления (несовпадающие размеры матриц; матрица, для которой
// нельзя провести вычисления и т.д.)

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int res = 0;

  if (checkMatrixForNull(A) && result) {
    if (A->columns == A->rows) {
      if (A->rows == 1 && A->matrix[0][0]) {
        res = s21_create_matrix(1, 1, result);
        result->matrix[0][0] = 1.0 / A->matrix[0][0];
      } else {
        double determinant = 0;
        s21_determinant(A, &determinant);
        if (determinant) {
          matrix_t tmp1 = {0};
          matrix_t tmp2 = {0};
          s21_calc_complements(A, &tmp1);
          s21_transpose(&tmp1, &tmp2);
          s21_mult_number(&tmp2, 1.0 / determinant, result);
          s21_remove_matrix(&tmp1);
          s21_remove_matrix(&tmp2);
        } else {
          res = 2;
        }
      }
    } else {
      res = 2;
    }
  } else {
    res = 1;
  }

  return res;
}