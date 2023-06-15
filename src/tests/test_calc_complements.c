#include "s21_test.h"

START_TEST(test_calc_complements_1) {
  matrix_t A = {0}, B = {0}, C = {0};
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &C);
  A.matrix[0][0] = 1.0;
  s21_calc_complements(&A, &B);
  C.matrix[0][0] = 0.0;
  int res = s21_eq_matrix(&B, &C);
  ck_assert_int_eq(res, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(test_calc_complements_2) {
  matrix_t A = {0}, B = {0}, C = {0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &C);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[1][0] = 0.0;
  A.matrix[1][1] = 4.0;
  s21_calc_complements(&A, &B);
  C.matrix[0][0] = 0.0;
  C.matrix[0][1] = 10.0;
  C.matrix[1][0] = 4.0;
  C.matrix[1][1] = -14.0;
  int res = s21_eq_matrix(&B, &C);
  ck_assert_int_eq(res, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(test_calc_complements_3) {
  matrix_t A = {0}, B = {0}, C = {0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &C);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[1][0] = 0.0;
  A.matrix[1][1] = 4.0;
  s21_calc_complements(&A, &B);
  C.matrix[0][0] = 0.0;
  C.matrix[0][1] = 10.0;
  C.matrix[1][0] = 4.0;
  C.matrix[1][1] = -14.0;
  int res = s21_eq_matrix(&B, &C);
  ck_assert_int_eq(res, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(test_calc_complements_4) {
  matrix_t A = {0}, B = {0}, C = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &C);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;
  A.matrix[1][0] = 0.0;
  A.matrix[1][1] = 4.0;
  A.matrix[1][2] = 2.0;
  A.matrix[2][0] = 5.0;
  A.matrix[2][1] = 2.0;
  A.matrix[2][2] = 1.0;
  s21_calc_complements(&A, &B);
  C.matrix[0][0] = 0.0;
  C.matrix[0][1] = 10.0;
  C.matrix[0][2] = -20.0;
  C.matrix[1][0] = 4.0;
  C.matrix[1][1] = -14.0;
  C.matrix[1][2] = 8.0;
  C.matrix[2][0] = -8.0;
  C.matrix[2][1] = -2.0;
  C.matrix[2][2] = 4.0;
  int res = s21_eq_matrix(&B, &C);
  ck_assert_int_eq(res, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(test_calc_complements_5) {
  matrix_t a = {0};
  matrix_t b = {0};
  ck_assert_int_eq(s21_calc_complements(&a, &b), INCORRECT_MATRIX);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(test_calc_complements_6) {
  matrix_t a = {0};
  matrix_t b = {0};
  s21_create_matrix(1, 2, &a);
  ck_assert_int_eq(s21_calc_complements(&a, &b), CALCULATION_ERROR);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(test_calc_complements_7) {
  const int size = 3;
  matrix_t m = {0};
  s21_create_matrix(size, size, &m);
  m.matrix[0][0] = 1;
  m.matrix[0][1] = 2;
  m.matrix[0][2] = 3;
  m.matrix[1][1] = 4;
  m.matrix[1][2] = 2;
  m.matrix[2][0] = 5;
  m.matrix[2][1] = 2;
  m.matrix[2][2] = 1;

  matrix_t expected = {0};
  s21_create_matrix(size, size, &expected);
  expected.matrix[0][1] = 10;
  expected.matrix[0][2] = -20;
  expected.matrix[1][0] = 4;
  expected.matrix[1][1] = -14;
  expected.matrix[1][2] = 8;
  expected.matrix[2][0] = -8;
  expected.matrix[2][1] = -2;
  expected.matrix[2][2] = 4;
  matrix_t res = {0};
  s21_calc_complements(&m, &res);
  ck_assert_int_eq(s21_eq_matrix(&expected, &res), SUCCESS);
  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(test_calc_complements_8) {
  matrix_t a = {0};
  matrix_t b = {0};
  s21_create_matrix(1, 2, &a);
  ck_assert_int_eq(s21_calc_complements(&a, &b), CALCULATION_ERROR);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

Suite *test_calc_complements(void) {
  Suite *s = suite_create("\033[45m-=S21_CALC_COMPLEMENTS=-\033[0m");
  TCase *tc = tcase_create("test_calc_complements_tc");

  tcase_add_test(tc, test_calc_complements_1);
  tcase_add_test(tc, test_calc_complements_2);
  tcase_add_test(tc, test_calc_complements_3);
  tcase_add_test(tc, test_calc_complements_4);
  tcase_add_test(tc, test_calc_complements_5);
  tcase_add_test(tc, test_calc_complements_6);
  tcase_add_test(tc, test_calc_complements_7);
  tcase_add_test(tc, test_calc_complements_8);

  suite_add_tcase(s, tc);
  return s;
}