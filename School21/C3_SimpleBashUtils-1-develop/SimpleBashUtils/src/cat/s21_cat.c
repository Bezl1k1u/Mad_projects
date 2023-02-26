#include "s21_cat.h"

int main(int argc, char *argv[]) {
  flags fcat = {FLAGS};
  flags_cat(argc, argv, &fcat);
  while (optind < argc) {
    read_file(argv, &fcat);
    optind++;
  }
  return 0;
}

int flags_cat(int argc, char *argv[], flags *fcat) {
  int flag;

  const char *short_options = "+bEnsTvet";

  static struct option long_options[] = {
      {0, 0, 0, 0},
      {"number-nonblank", 0, 0, 'b'},
      {"number", 0, 0, 'n'},
      {"squeeze-blank", 0, 0, 's'},
  };

  while ((flag = getopt_long(argc, argv, short_options, long_options, NULL)) !=
         -1) {
    switch (flag) {
      case 'b':
        fcat->b = 1;
        break;
      case 'E':
        fcat->e = 1;
        break;
      case 'n':
        fcat->n = 1;
        break;
      case 's':
        fcat->s = 1;
        break;
      case 'T':
        fcat->t = 1;
        break;
      case 'v':
        fcat->v = 1;
        break;
      case 'e':
        fcat->e = 1;
        fcat->v = 1;
        break;
      case 't':
        fcat->t = 1;
        fcat->v = 1;
        break;
      default:
        printf("err\n");
        break;
    }
    if (fcat->b && fcat->n) fcat->n = 0;
  }
  return 0;
}

void read_file(char *argv[], flags *fcat) {
  FILE *fp;
  fp = fopen(argv[optind], "r");
  if (fp != NULL) {
    int str_count = 1;
    int empty_str_count = 0;
    int last = '\n';
    while (!feof(fp)) {
      int c = fgetc(fp);
      if (c == EOF) break;
      if (fcat->s && c == '\n' && last == '\n') {
        empty_str_count++;
        if (empty_str_count > 1) {
          continue;
        }
      } else {
        empty_str_count = 0;
      }
      if (last == '\n' && ((fcat->b && c != '\n') || fcat->n))
        printf("%6d\t", str_count++);
      if (fcat->t && c == '\t') {
        printf("^");
        c = 'I';
      }
      if (fcat->e && c == '\n') printf("$");
      if (fcat->v) {
        if ((c >= 0 && c < 9) || (c > 10 && c < 32)) {
          printf("^");
          c += 64;
        }
        if (c == 127) {
          printf("^");
          c -= 64;
        }
      }
      printf("%c", c);
      last = c;
    }
    fclose(fp);
  } else {
    fprintf(stderr, "s21: %s: No such file or directory\n", argv[optind]);
  }
}
