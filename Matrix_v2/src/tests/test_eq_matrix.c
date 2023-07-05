#include "test_matrix.h"

START_TEST(eq_matrix_1) {
  matrix_t A = {NULL, 0, 0}, B = {NULL, 0, 0};
  int rows = 3, cols = 3;
  s21_create_matrix(rows, cols, &A);
  s21_create_matrix(rows, cols, &B);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      A.matrix[i][j] = 349.43;
      B.matrix[i][j] = 349.43;
    }
  }
  double tmp = 17.4389;
  matrix_t dst1 = {NULL, 0, 0}, dst2 = {NULL, 0, 0};
  s21_mult_number(&A, tmp, &dst1);
  s21_mult_number(&B, tmp, &dst2);
  int state = s21_eq_matrix(&dst1, &dst2);
  ck_assert_int_eq(state, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&dst1);
  s21_remove_matrix(&dst2);
}
END_TEST

START_TEST(eq_matrix_2) {
  matrix_t A = {NULL, 0, 0}, B = {NULL, 0, 0};
  int rows = 3, cols = 3;
  s21_create_matrix(rows, cols, &A);
  s21_create_matrix(3, 4, &B);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      A.matrix[i][j] = 349.43;
    }
  }
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < 4; j++) {
      B.matrix[i][j] = 349.43;
    }
  }
  double tmp = 17.4389;
  matrix_t dst1 = {NULL, 0, 0}, dst2 = {NULL, 0, 0};
  s21_mult_number(&A, tmp, &dst1);
  s21_mult_number(&B, tmp, &dst2);
  int state = s21_eq_matrix(&dst1, &dst2);
  ck_assert_int_eq(state, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&dst1);
  s21_remove_matrix(&dst2);
}
END_TEST

START_TEST(eq_matrix_3) {
  matrix_t *A = NULL, B = {NULL, 0, 0};
  int rows = 3, cols = 3;
  s21_create_matrix(rows, cols, &B);
  int state = s21_eq_matrix(A, &B);
  ck_assert_int_eq(state, FAILURE);
  s21_remove_matrix(A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_4) {
  matrix_t A = {NULL, 0, 0}, B = {NULL, 0, 0};
  int rows = 3, cols = 3;
  s21_create_matrix(rows, cols, &B);
  int state = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(state, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *test_eq_matrix() {
  Suite *s = suite_create(color_text("S21_EQ_MATRIX"));
  TCase *tc = tcase_create("eq_matrix");

  tcase_add_test(tc, eq_matrix_1);
  tcase_add_test(tc, eq_matrix_2);
  tcase_add_test(tc, eq_matrix_3);
  tcase_add_test(tc, eq_matrix_4);

  suite_add_tcase(s, tc);
  return s;
}
