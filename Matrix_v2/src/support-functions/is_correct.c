#include "../s21_matrix.h"

int isCorrect(matrix_t* A) {
  int state = FALSE;
  if (A && A->matrix && A->rows > 0 && A->columns > 0) state = TRUE;
  return state;
}
