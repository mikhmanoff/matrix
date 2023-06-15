#include "support.h"

#include "s21_matrix.h"

int checkMatrixForNull(matrix_t* A) {  // 1 - OK
  int result = 1;

  if (A == NULL || A->matrix == NULL || A->rows <= 0 || A->columns <= 0) {
    result = 0;
  } else {
    result = 1;
  }

  return result;
}

void minorMatrix(matrix_t* A, matrix_t* result, int row, int col) {
  for (int i = 0, rowMinor = 0; rowMinor < A->rows; rowMinor++) {
    if (rowMinor == row) continue;
    for (int j = 0, columnMinor = 0; columnMinor < A->columns; columnMinor++) {
      if (columnMinor == col) continue;

      result->matrix[i][j] = A->matrix[rowMinor][columnMinor];
      j++;
    }
    i++;
  }
}

double determinant(matrix_t* A) {
  double res = 0.;

  if (A->rows == 1) {
    res = A->matrix[0][0];
  } else {
    matrix_t tmp = {0};
    s21_create_matrix(A->rows - 1, A->columns - 1, &tmp);

    for (int i = 0; i < A->rows; i++) {
      minorMatrix(A, &tmp, 0, i);
      res += pow(-1, i) * A->matrix[0][i] * determinant(&tmp);
    }

    s21_remove_matrix(&tmp);
  }

  return res;
}