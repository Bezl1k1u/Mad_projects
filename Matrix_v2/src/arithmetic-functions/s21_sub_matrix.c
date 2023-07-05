#include "../s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int state = OK;
  if (isCorrect(A) && isCorrect(B) && result) {
    if (equalSize(A, B)) {
      s21_create_matrix(A->rows, A->columns, result);
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
        }
      }
    } else
      state = ERROR_CALC;
  } else
    state = INVALID_MATRIX;
  return state;
}
