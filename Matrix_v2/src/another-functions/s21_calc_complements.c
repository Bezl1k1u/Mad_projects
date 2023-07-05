#include "../s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int state = OK;
  if (isCorrect(A) && result) {
    if (A->rows == A->columns) {
      s21_create_matrix(A->rows, A->columns, result);
      double determinant = 0;
      matrix_t tmp = {NULL, 0, 0};
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          getOffsetMatrix(A, i, j, &tmp);
          s21_determinant(&tmp, &determinant);
          result->matrix[i][j] = determinant * pow(-1, (i + j));
          s21_remove_matrix(&tmp);
        }
      }
    } else
      state = ERROR_CALC;
  } else
    state = INVALID_MATRIX;
  return state;
}
