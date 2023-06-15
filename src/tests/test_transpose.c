#include "s21_test.h"

START_TEST(test_transpose_1) {
  matrix_t A, RES, REAL;

  ck_assert_int_eq(s21_create_matrix(3, 2, &A), 0);
  ck_assert_int_eq(s21_create_matrix(2, 3, &REAL), 0);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = (rand() % 10 < 5 ? 1 : -1) * rand() % 100;
      REAL.matrix[j][i] = A.matrix[i][j];
    }
  }
  ck_assert_int_eq(s21_transpose(&A, &RES), OK);
  ck_assert_int_eq(s21_eq_matrix(&RES, &REAL), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&RES);
  s21_remove_matrix(&REAL);
}
END_TEST

Suite *test_transpose(void) {
  Suite *s = suite_create("\033[45m-=S21_TRANSPOSE=-\033[0m");
  TCase *tc = tcase_create("test_transpose_tc");

  tcase_add_test(tc, test_transpose_1);
  //   tcase_add_test(tc, test_transpose_2);

  suite_add_tcase(s, tc);
  return s;
}