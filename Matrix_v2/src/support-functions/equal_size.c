#include "../s21_matrix.h"

int equalSize(matrix_t* A, matrix_t* B) {
  int state = FALSE;
  if (A->rows == B->rows && A->columns == B->columns) state = TRUE;
  return state;
}
