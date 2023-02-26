#ifndef SRC_GREP_S21_GREP_H_
#define SRC_GREP_S21_GREP_H_

#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 4096
typedef struct fgrep {
  int e;
  int i;
  int v;
  int c;
  int l;
  int n;
  int h;
  int s;
  int f;
  int o;
  char emass[4096];
  int files_count;
} flags;

void flag_grep(int argc, char *argv[], flags *fgrep);
void read_file(flags *fgrep, char *filename);
int f_flag(flags *fgrep, char *temp);
int get_pattern(flags *fgrep, char *optarg);

#endif  // SRC_GREP_S21_GREP_H_