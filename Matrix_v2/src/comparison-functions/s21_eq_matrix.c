#include "../s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int state = SUCCESS;
  if (isCorrect(A) && isCorrect(B) && equalSize(A, B)) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 1e-07) state = FAILURE;
      }
    }
  } else
    state = FAILURE;
  return state;
}
