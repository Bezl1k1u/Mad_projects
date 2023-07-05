#include "test_matrix.h"

START_TEST(transpose_1) {
  matrix_t A = {NULL, 2, 3};
  matrix_t B = {NULL, 3, 2};
  int aCounter = 1;
  // Fill A
  s21_create_matrix(A.rows, A.columns, &A);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = aCounter++;
    }
  }
  // Fill B
  s21_create_matrix(B.rows, B.columns, &B);
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 4;
  B.matrix[1][0] = 2;
  B.matrix[1][1] = 5;
  B.matrix[2][0] = 3;
  B.matrix[2][1] = 6;
  // Transpose
  matrix_t result = {NULL, 0, 0};
  int state = s21_transpose(&A, &result);
  ck_assert_int_eq(state, OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &B), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(transpose_2) {
  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(2, 2, &A);
  matrix_t *result = NULL;
  int state = s21_transpose(&A, result);
  ck_assert_int_eq(state, INVALID_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(transpose_3) {
  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(1, 1, &A);
  matrix_t result = {NULL, 0, 0};
  int state = s21_transpose(&A, &result);
  ck_assert_int_eq(state, OK);
  s21_remove_matrix(&A);
}
END_TEST

Suite *test_transpose_matrix() {
  Suite *s = suite_create(color_text("S21_TRANSPOSE_MATRIX"));
  TCase *tc = tcase_create("transpose");

  tcase_add_test(tc, transpose_1);
  tcase_add_test(tc, transpose_2);
  tcase_add_test(tc, transpose_3);

  suite_add_tcase(s, tc);
  return s;
}
