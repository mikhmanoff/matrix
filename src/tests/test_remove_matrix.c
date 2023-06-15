#include "s21_test.h"

START_TEST(test_remove_matrix_1) {
  int res = 0;
  matrix_t A = {0};

  res = s21_create_matrix(2, 2, &A);
  s21_remove_matrix(&A);
  if (A.matrix != NULL) {
    res = INCORRECT_MATRIX;
  }
  ck_assert_int_eq(res, OK);
}
END_TEST

START_TEST(test_remove_matrix_2) {
  int res = 0;
  matrix_t A = {0};

  res = s21_create_matrix(1, 1, &A);
  s21_remove_matrix(&A);
  if (A.matrix != NULL) {
    res = INCORRECT_MATRIX;
  }
  ck_assert_int_eq(res, OK);
}
END_TEST

START_TEST(test_remove_matrix_3) {
  int res = 0;
  matrix_t A = {0};

  res = s21_create_matrix(3, 2, &A);
  s21_remove_matrix(&A);
  if (A.matrix != NULL) {
    res = INCORRECT_MATRIX;
  }
  ck_assert_int_eq(res, OK);
}
END_TEST

START_TEST(test_remove_matrix_4) {
  int res = 0;
  matrix_t A = {0};

  res = s21_create_matrix(3, 4, &A);
  s21_remove_matrix(&A);
  if (A.matrix != NULL) {
    res = INCORRECT_MATRIX;
  }
  ck_assert_int_eq(res, OK);
}
END_TEST

START_TEST(test_remove_matrix_5) {
  int res = 0;
  matrix_t A = {0};

  res = s21_create_matrix(3, 2, &A);
  s21_remove_matrix(&A);
  if (A.matrix != NULL) {
    res = INCORRECT_MATRIX;
  }
  ck_assert_int_eq(res, OK);
}
END_TEST

Suite *test_remove_matrix(void) {
  Suite *s = suite_create("\033[45m-=S21_REMOVE_MATRIX=-\033[0m");
  TCase *tc = tcase_create("test_remove_matrix_tc");

  tcase_add_test(tc, test_remove_matrix_1);
  tcase_add_test(tc, test_remove_matrix_2);
  tcase_add_test(tc, test_remove_matrix_3);
  tcase_add_test(tc, test_remove_matrix_4);
  tcase_add_test(tc, test_remove_matrix_5);

  suite_add_tcase(s, tc);
  return s;
}