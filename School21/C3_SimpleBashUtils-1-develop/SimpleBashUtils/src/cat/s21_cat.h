#ifndef SRC_CAT_S21_CAT_H_
#define SRC_CAT_S21_CAT_H_

#include <errno.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct fcat {
  int b;
  int e;
  int n;
  int s;
  int t;
  int v;
} flags;

#define FLAGS .b = 0, .e = 0, .n = 0, .s = 0, .t = 0, .v = 0,

int flags_cat(int argc, char *argv[], flags *fcat);
void read_file(char *argv[], flags *fcat);

#endif  // SRC_CAT_S21_CAT_H_
