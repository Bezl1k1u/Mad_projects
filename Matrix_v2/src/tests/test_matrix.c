#include "test_matrix.h"

static void run_test(Suite *s, int *failed) {
  SRunner *sr = srunner_create(s);

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);

  *failed += srunner_ntests_failed(sr);
  srunner_free(sr);
}

int main() {
  int failed = 0;
  Suite *s21_matrix_test[] = {test_create_matrix(),
                              test_eq_matrix(),
                              test_sum_matrix(),
                              test_sub_matrix(),
                              test_mult_matrix(),
                              test_mult_number(),
                              test_transpose_matrix(),
                              test_determinant(),
                              test_calc_complements(),
                              test_inverse_matrix(),
                              NULL};

  printf("\n" color_start("====== TESTING ======") "\n\n");

  for (Suite **s = s21_matrix_test; *s != NULL; s++) {
    run_test(*s, &failed);
  }

  printf("\n" color_start("====== FAILED: %d ======") "\n", failed);

  return (failed) ? 1 : 0;
}
