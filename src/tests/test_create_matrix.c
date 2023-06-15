#include "s21_test.h"

START_TEST(test_create_matrix_1) {
  srand(time(NULL));
  matrix_t A;
  ck_assert_int_eq(s21_create_matrix(rand() % 100, rand() % 100, &A), OK);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_create_matrix_2) {
  srand(time(NULL));
  matrix_t A;
  ck_assert_int_eq(s21_create_matrix(-rand() % 100, rand() % 100, &A),
                   INCORRECT_MATRIX);
}
END_TEST

START_TEST(test_create_matrix_3) {
  srand(time(NULL));
  matrix_t A;
  ck_assert_int_eq(s21_create_matrix(rand() % 100, -rand() % 100, &A),
                   INCORRECT_MATRIX);
}
END_TEST

START_TEST(test_create_matrix_4) {
  srand(time(NULL));
  matrix_t A;
  ck_assert_int_eq(s21_create_matrix(-rand() % 100, -rand() % 100, &A),
                   INCORRECT_MATRIX);
}
END_TEST

START_TEST(test_create_matrix_5) {
  srand(time(NULL));
  ck_assert_int_eq(s21_create_matrix(-rand() % 100, rand() % 100, NULL),
                   INCORRECT_MATRIX);
}
END_TEST

Suite *test_create_matrix(void) {
  Suite *s = suite_create("\033[45m-=S21_CREATE_MATRIX=-\033[0m");
  TCase *tc = tcase_create("test_create_matrix_tc");

  tcase_add_test(tc, test_create_matrix_1);
  tcase_add_test(tc, test_create_matrix_2);
  tcase_add_test(tc, test_create_matrix_3);
  tcase_add_test(tc, test_create_matrix_4);
  tcase_add_test(tc, test_create_matrix_5);

  suite_add_tcase(s, tc);
  return s;
}