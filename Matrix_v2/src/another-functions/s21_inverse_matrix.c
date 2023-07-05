#include "../s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int state = OK;
  if (isCorrect(A) && result) {
    double determinant = 0;
    s21_determinant(A, &determinant);
    if (A->rows == A->columns && determinant != 0) {
      // Calculate matrix of algebraic complements
      matrix_t complements = {NULL, 0, 0};
      s21_calc_complements(A, &complements);
      matrix_t complementsTranspose = {NULL, 0, 0};
      // Transpose matrix of algebraic complements
      s21_transpose(&complements, &complementsTranspose);
      // Multiply by 1 / |A|
      s21_mult_number(&complementsTranspose, (1 / determinant), result);
      s21_remove_matrix(&complements);
      s21_remove_matrix(&complementsTranspose);
    } else
      state = ERROR_CALC;
  } else
    state = INVALID_MATRIX;
  return state;
}
