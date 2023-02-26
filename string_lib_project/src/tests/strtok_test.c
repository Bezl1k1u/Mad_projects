#include "tests.h"

START_TEST(strtok_1) {
  char str4_1[10000] = "/testing/with/original/string.h/";
  char str4_2[10000] = "/testing/with/original/string.h/";
  char del4[30] = "/";
  char *nstr_1, *nstr_2;
  nstr_1 = strtok(str4_1, del4);
  nstr_2 = s21_strtok(str4_2, del4);
  while (nstr_1 != S21_NULL || nstr_2 != S21_NULL) {
    ck_assert_pstr_eq(nstr_1, nstr_2);
    nstr_1 = strtok(S21_NULL, del4);
    nstr_2 = s21_strtok(S21_NULL, del4);
  }
}
END_TEST

START_TEST(strtok_2) {
  char str4_1[10000] = ". . testing with original string.h";
  char str4_2[10000] = ". . testing with original string.h";
  char del4[30] = ". ";

  char *nstr_1, *nstr_2;
  nstr_1 = strtok(str4_1, del4);
  nstr_2 = s21_strtok(str4_2, del4);
  while (nstr_1 != S21_NULL) {
    ck_assert_pstr_eq(nstr_1, nstr_2);
    nstr_1 = strtok(S21_NULL, del4);
    nstr_2 = s21_strtok(S21_NULL, del4);
  }
}
END_TEST

START_TEST(strtok_3) {
  char str4_1[10000] = "testing with original string.h";
  char str4_2[10000] = "testing with original string.h";
  char del4[3] = ". ";
  char *nstr_1, *nstr_2;
  nstr_1 = strtok(str4_1, del4);
  nstr_2 = s21_strtok(str4_2, del4);
  while (nstr_1 != S21_NULL) {
    ck_assert_pstr_eq(nstr_1, nstr_2);
    nstr_1 = strtok(S21_NULL, del4);
    nstr_2 = s21_strtok(S21_NULL, del4);
  }
}
END_TEST

START_TEST(strtok_correct_token_string) {
  char str1[10000] = "Aboba++Floppa_! Kotya====!Shleppa";
  char str2[10000] = "Aboba++Floppa_! Kotya====!Shleppa";
  const char delims[30] = "+_! =";
  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);
  while (got && expected) {
    got = s21_strtok(S21_NULL, delims);
    expected = strtok(S21_NULL, delims);
    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(strtok_hard_token_string) {
  char str1[10000] = "++Aboba++Floppa_! Kotya===!Shleppa+++ A +";
  char str2[10000] = "++Aboba++Floppa_! Kotya===!Shleppa+++ A +";
  const char delims[30] = "+_! =";
  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);
  while (got && expected) {
    expected = strtok(S21_NULL, delims);
    got = s21_strtok(S21_NULL, delims);
    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(strtok_unary_delimiters) {
  char str1[10000] = "Aboba+Anuroba_Floppa!Kotya_Kekus";
  char str2[10000] = "Aboba+Anuroba_Floppa!Kotya_Kekus";
  const char delims[30] = "+_! =";
  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);
  while (got && expected) {
    got = s21_strtok(S21_NULL, delims);
    expected = strtok(S21_NULL, delims);
    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(strtok_no_delims) {
  char str1[10000] = "AbobaHasNoDelims";
  char str2[10000] = "AbobaHasNoDelims";
  const char delims[30] = "+_! =";
  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);
  while (got && expected) {
    got = s21_strtok(S21_NULL, delims);
    expected = strtok(S21_NULL, delims);
    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(strtok_only_delims) {
  char str1[10000] = "++++++++";
  char str2[10000] = "++++++++";
  const char delims[30] = "+_! =";
  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_ptr_null(got);
  ck_assert_ptr_null(expected);
}
END_TEST

START_TEST(strtok_too_many_uses_non_segfault) {
  char str1[10000] = "Aboba_Floppa_Roba";
  char str2[10000] = "Aboba_Floppa_Roba";
  const char delims[30] = "+_! =";
  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);
  int i = 5;
  while (i) {
    got = s21_strtok(S21_NULL, delims);
    expected = strtok(S21_NULL, delims);
    i--;
    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(strtok_even_n_of_delims) {
  char str1[10000] = "Roba++++Kepa++A++++B__V";
  char str2[10000] = "Roba++++Kepa++A++++B__V";
  const char delims[30] = "+_! =";
  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);
  while (got && expected) {
    got = s21_strtok(S21_NULL, delims);
    expected = strtok(S21_NULL, delims);
    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(strtok_odd_n_of_delims) {
  char str1[10000] = "Aboba__+Floppa_  Roba";
  char str2[10000] = "Aboba__+Floppa_  Roba";
  const char delims[30] = "+_! =";
  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);
  while (got && expected) {
    got = s21_strtok(S21_NULL, delims);
    expected = strtok(S21_NULL, delims);
    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(strtok_mixed_n_of_delims) {
  char str1[10000] = "Aboba__Floppa_+++Roba_Kepa";
  char str2[10000] = "Aboba__Floppa_+++Roba_Kepa";
  const char delims[30] = "+_! =";
  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);
  while (got && expected) {
    got = s21_strtok(S21_NULL, delims);
    expected = strtok(S21_NULL, delims);
    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(strtok_hard_mixed) {
  char str1[10000] = "     Aboba__+ Flo!ppa_   Roba+";
  char str2[10000] = "     Aboba__+ Flo!ppa_   Roba+";
  const char delims[30] = "+_! =";
  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);
  while (got || expected) {
    got = s21_strtok(S21_NULL, delims);
    expected = strtok(S21_NULL, delims);
    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(strtok_mixed_hard_incorrect) {
  char str1[10000] = "!Stepa__ !M!ish a____Anton+An!!!drey";
  char str2[10000] = "!Stepa__ !M!ish a____Anton+An!!!drey";
  const char delims[30] = "+_! =";
  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);
  while (got || expected) {
    got = s21_strtok(S21_NULL, delims);
    expected = strtok(S21_NULL, delims);
    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(strtok_very_hard_mixed) {
  char str1[10000] = "!       A!B!C!D!E!!F!!G";
  char str2[10000] = "!       A!B!C!D!E!!F!!G";
  const char delims[30] = "+_! =";
  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);
  while (got || expected) {
    got = s21_strtok(S21_NULL, delims);
    expected = strtok(S21_NULL, delims);
    if (got || expected) {
      ck_assert_str_eq(got, expected);
      ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

Suite *suite_strtok(void) {
  Suite *s = suite_create("suite_strtok");
  TCase *tc = tcase_create("strtok_tc");
  tcase_add_test(tc, strtok_1);
  tcase_add_test(tc, strtok_2);
  tcase_add_test(tc, strtok_3);
  tcase_add_test(tc, strtok_correct_token_string);
  tcase_add_test(tc, strtok_hard_token_string);
  tcase_add_test(tc, strtok_unary_delimiters);
  tcase_add_test(tc, strtok_no_delims);
  tcase_add_test(tc, strtok_only_delims);
  tcase_add_test(tc, strtok_too_many_uses_non_segfault);
  tcase_add_test(tc, strtok_even_n_of_delims);
  tcase_add_test(tc, strtok_odd_n_of_delims);
  tcase_add_test(tc, strtok_mixed_n_of_delims);
  tcase_add_test(tc, strtok_hard_mixed);
  tcase_add_test(tc, strtok_mixed_hard_incorrect);
  tcase_add_test(tc, strtok_very_hard_mixed);

  suite_add_tcase(s, tc);
  return s;
}
