#include "s21_test.h"

START_TEST(test_mult_number_1) {
  matrix_t A, RES, REAL;
  s21_create_matrix(10, 10, &A);
  s21_create_matrix(10, 10, &REAL);
  double n = (rand() % 1000 + 100) * 2;
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = rand() % 100 + (rand() % 10000) / 1000000;
      REAL.matrix[i][j] = A.matrix[i][j] * n;
    }
  }
  ck_assert_int_eq(s21_mult_number(&A, n, &RES), OK);
  ck_assert_int_eq(s21_eq_matrix(&RES, &REAL), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&RES);
  s21_remove_matrix(&REAL);
}
END_TEST

START_TEST(test_mult_number_2) {
  matrix_t A, RES, REAL;
  s21_create_matrix(10, 10, &A);
  s21_create_matrix(10, 10, &REAL);
  double n = 0;
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = rand() % 100 + (rand() % 10000) / 1000000;
      REAL.matrix[i][j] = A.matrix[i][j] * n;
    }
  }
  ck_assert_int_eq(s21_mult_number(&A, n, &RES), OK);
  ck_assert_int_eq(s21_eq_matrix(&RES, &REAL), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&RES);
  s21_remove_matrix(&REAL);
}
END_TEST

Suite *test_mult_number(void) {
  Suite *s = suite_create("\033[45m-=S21_MULT_NUMBER=-\033[0m");
  TCase *tc = tcase_create("test_mult_number_tc");

  tcase_add_test(tc, test_mult_number_1);
  tcase_add_test(tc, test_mult_number_2);

  suite_add_tcase(s, tc);
  return s;
}