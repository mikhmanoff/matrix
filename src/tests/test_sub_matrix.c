#include "s21_test.h"

START_TEST(test_sub_matrix_1) {
  matrix_t A, B, RES, REAL;
  s21_create_matrix(10, 10, &A);
  s21_create_matrix(10, 10, &B);
  s21_create_matrix(10, 10, &REAL);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = rand() % 100 + (rand() % 10000) / 1000000;
      B.matrix[i][j] = rand() % 100 + (rand() % 10000) / 1000000;
      REAL.matrix[i][j] = A.matrix[i][j] - B.matrix[i][j];
    }
  }
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &RES), OK);
  ck_assert_int_eq(s21_eq_matrix(&RES, &REAL), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&RES);
  s21_remove_matrix(&REAL);
}
END_TEST

START_TEST(test_sub_matrix_2) {
  matrix_t A, B, RES, REAL;
  s21_create_matrix(10, 20, &A);
  s21_create_matrix(10, 20, &B);
  s21_create_matrix(10, 20, &REAL);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = (rand() % 10 < 5 ? 1 : -1) * rand() % 100 +
                       (rand() % 10000) / 1000000;
      B.matrix[i][j] = rand() % 100 + (rand() % 10000) / 1000000;
      REAL.matrix[i][j] = A.matrix[i][j] - B.matrix[i][j];
    }
  }
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &RES), OK);
  ck_assert_int_eq(s21_eq_matrix(&RES, &REAL), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&RES);
  s21_remove_matrix(&REAL);
}
END_TEST

START_TEST(test_sub_matrix_3) {
  matrix_t A, B, RES, REAL;
  s21_create_matrix(10, 1, &A);
  s21_create_matrix(10, 1, &B);
  s21_create_matrix(10, 1, &REAL);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = (rand() % 10 < 5 ? 1 : -1) * rand() % 100 +
                       (rand() % 10000) / 1000000;
      B.matrix[i][j] = (rand() % 10 < 5 ? 1 : -1) * rand() % 100 +
                       (rand() % 10000) / 1000000;
      REAL.matrix[i][j] = A.matrix[i][j] - B.matrix[i][j];
    }
  }
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &RES), OK);
  ck_assert_int_eq(s21_eq_matrix(&RES, &REAL), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&RES);
  s21_remove_matrix(&REAL);
}
END_TEST

START_TEST(test_sub_matrix_4) {
  matrix_t A, B, RES;
  s21_create_matrix(10, 1, &A);
  s21_create_matrix(10, 2, &B);
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &RES), CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_sub_matrix_5) {
  matrix_t A, B, RES;
  s21_create_matrix(10, 50, &A);
  s21_create_matrix(1, 50, &B);
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &RES), CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_sub_matrix_6) {
  matrix_t B, RES;
  s21_create_matrix(1, 50, &B);
  ck_assert_int_eq(s21_sub_matrix(NULL, &B, &RES), INCORRECT_MATRIX);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_sub_matrix_7) {
  matrix_t A, B;
  s21_create_matrix(10, 50, &A);
  s21_create_matrix(10, 50, &B);

  ck_assert_int_eq(s21_sub_matrix(&A, &B, NULL), INCORRECT_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *test_sub_matrix(void) {
  Suite *s = suite_create("\033[45m-=S21_SUB_MATRIX=-\033[0m");
  TCase *tc = tcase_create("test_sub_matrix_tc");

  tcase_add_test(tc, test_sub_matrix_1);
  tcase_add_test(tc, test_sub_matrix_2);
  tcase_add_test(tc, test_sub_matrix_3);
  tcase_add_test(tc, test_sub_matrix_4);
  tcase_add_test(tc, test_sub_matrix_5);
  tcase_add_test(tc, test_sub_matrix_6);
  tcase_add_test(tc, test_sub_matrix_7);

  suite_add_tcase(s, tc);
  return s;
}