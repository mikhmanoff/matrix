#include "s21_test.h"

START_TEST(test_eq_1) {
  srand(time(NULL));
  matrix_t A;
  s21_create_matrix(15, 15, &A);
  matrix_t B;
  s21_create_matrix(15, 15, &B);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = rand() % 100 + (rand() % 10000) / 1000000;
      B.matrix[i][j] = rand() % 100 + (rand() % 10000) / 1000000;
    }
  }
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_eq_2) {
  srand(time(NULL));
  matrix_t A;
  s21_create_matrix(15, 15, &A);
  matrix_t B;
  s21_create_matrix(15, 15, &B);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = rand() % 100 + (rand() % 10000) / 1000000;
      B.matrix[i][j] = A.matrix[i][j];
    }
  }
  ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_eq_3) {
  srand(time(NULL));
  matrix_t A;
  s21_create_matrix(3, 10, &A);
  matrix_t B;
  s21_create_matrix(5, 5, &B);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *test_eq_matrix(void) {
  Suite *s = suite_create("\033[45m-=S21_EQ_MATRIX=-\033[0m");
  TCase *tc = tcase_create("test_eq_matrix_tc");

  tcase_add_test(tc, test_eq_1);
  tcase_add_test(tc, test_eq_2);
  tcase_add_test(tc, test_eq_3);

  suite_add_tcase(s, tc);
  return s;
}