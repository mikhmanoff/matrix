#include "s21_matrix.h"
#include "support.h"

// SUCCESS 1
// FAILURE 0

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int res = SUCCESS;

  if (A->columns == B->columns && A->rows == B->rows) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) < 1e-7) {
          res = SUCCESS;  // нужно протестировать
        } else {
          res = FAILURE;
        }
      }
    }
  } else {
    res = FAILURE;
  }

  return res;
}