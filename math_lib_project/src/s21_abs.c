#include "s21_math.h"

int s21_abs(int x) {
  int result = 0;
  if (x >= 0)
    result = x;
  else
    result = -x;
  return result;
}
