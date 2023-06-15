#include "s21_test.h"

START_TEST(test_mult_matrix_1) {
  matrix_t A, B, RES, REAL;

  ck_assert_int_eq(s21_create_matrix(3, 2, &A), 0);
  ck_assert_int_eq(s21_create_matrix(2, 3, &B), 0);
  ck_assert_int_eq(s21_create_matrix(3, 3, &REAL), 0);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = (rand() % 10 < 5 ? 1 : -1) * rand() % 100;
    }
  }
  for (int i = 0; i < B.rows; i++) {
    for (int j = 0; j < B.columns; j++) {
      B.matrix[i][j] = (rand() % 10 < 5 ? 1 : -1) * rand() % 100;
    }
  }
  for (int i = 0; i < REAL.rows; i++) {
    for (int j = 0; j < REAL.columns; j++) {
      REAL.matrix[i][j] = 0;
      for (int m = 0; m < B.rows; m++)
        REAL.matrix[i][j] += A.matrix[i][m] * B.matrix[m][j];
    }
  }
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &RES), OK);
  ck_assert_int_eq(s21_eq_matrix(&RES, &REAL), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&RES);
  s21_remove_matrix(&REAL);
}
END_TEST

START_TEST(test_mult_matrix_2) {
  matrix_t A, B, REAL;

  ck_assert_int_eq(s21_create_matrix(3, 1, &A), 0);
  ck_assert_int_eq(s21_create_matrix(2, 3, &B), 0);

  ck_assert_int_eq(s21_mult_matrix(&A, &B, &REAL), CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *test_mult_matrix(void) {
  Suite *s = suite_create("\033[45m-=S21_MULT_MATRIX=-\033[0m");
  TCase *tc = tcase_create("test_mult_matrix_tc");

  tcase_add_test(tc, test_mult_matrix_1);
  tcase_add_test(tc, test_mult_matrix_2);

  suite_add_tcase(s, tc);
  return s;
}