#include "s21_grep.h"

int main(int argc, char *argv[]) {
  flags fgrep = {0};

  /* вызываем функцию для разбора, будем парсить */
  flag_grep(argc, argv, &fgrep);
  if (fgrep.e == 0 && fgrep.f == 0) {
    get_pattern(&fgrep, argv[optind]);
    optind++;
  }
  fgrep.files_count = argc - optind;
  if (fgrep.l == 1 || fgrep.c == 1 || fgrep.v == 1) {
    fgrep.o = 0;
  }

  for (int i = optind; i < argc; i++) {
    char *filename = argv[i];
    read_file(&fgrep, filename);
  }
  return 0;
}

void flag_grep(int argc, char *argv[], flags *fgrep) {
  int opt;
  const char *short_options = "e:ivclnhsf:o";  // почему  Е:

  while ((opt = getopt_long(argc, argv, short_options, NULL, NULL)) != -1) {
    switch (opt) {
      case 'e':
        get_pattern(fgrep, optarg);
        fgrep->e = 1;  // указать несколько шаблонов (F)
        break;
      case 'i':
        fgrep->i = 1;  // искать паттерн, не глядя на его регистр (F)
        break;
      case 'v':
        fgrep->v = 1;  // найти что-то несоответствующее заданному шаблону (F)
        break;
      case 'c':
        fgrep->c =
            1;  // Выдает только количество строк, содержащих образец. (F)
        break;
      case 'l':
        fgrep->l = 1;  // Выдает только имена файлов, содержащих сопоставившиеся
        // строки, по одному в строке. Если образец найден в
        // нескольких строках файла, имя файла не повторяется (F)
        break;
      case 'n':
        fgrep->n =
            1;  // номера найденных строк, чтобы узнать их позицию в файле (F)
        break;
      case 'h':
        fgrep->h = 1;  // Предотвращает выдачу имени файла, содержащего
        // сопоставившуюся строку, перед собственно строкой.
        // Используется при поиске по нескольким файлам. (F)
        break;
      case 's':
        fgrep->s = 1;  // Подавляет выдачу сообщений о не существующих или
        // недоступных для чтения файлах.
        break;
      case 'f':
        f_flag(fgrep, optarg);
        fgrep->f = 1;  // Аргумент шаблона — это имя файла, содержащего
        // регулярные выражения по одному на строку
        break;
      case 'o':
        fgrep->o = 1;  // Возвращает не всю строку, где найдено соответствие
        // ОБРАЗЦУ, а только совпадающую с ОБРАЗЦОМ часть строки.
        break;
      default:
        printf(
            "Usage [-e, -i, -v, -c, -l, -n, -h, -s, -f, -o] template "
            "[file_name]");
        exit(1);
    }
  }
}

int get_pattern(flags *fgrep, char *optarg) {
  if (fgrep->e == 0 && fgrep->f == 0) {
    strcpy(fgrep->emass, optarg);
  } else {
    strcat(fgrep->emass, "|");
    strcat(fgrep->emass, optarg);
  }
  return 0;
}

/* чтение файла и обработка флагов*/
void read_file(flags *fgrep, char *filename) {
  FILE *fp = fopen(filename, "r");  // открываем на чтение
  if (fp) {
    char str[BUFSIZE] = {0};
    int str_count = 1;
    int empty_str_count = 0;
    int last = 0;
    int status = 0;
    int success = 0;

    int cflags = REG_EXTENDED;  // используем синтаксис расширенных регулярных
    // выражений POSIX во время интерпретации regex
    if (fgrep->i) cflags = REG_EXTENDED | REG_ICASE;  //Не учитывать регистр
    regex_t preg;
    regmatch_t pm[1];  // подготавливаем массив к поиску, используется для
    // представления местоположения подвыражений в регулярном
    // выражении
    status = regcomp(&preg, fgrep->emass, cflags);
    // printf("%d\n",status);
    while (fgets(str, BUFSIZE - 1, fp) != NULL) {
      status = regexec(
          &preg, str, 1, pm,
          0);  // ищем слово, используем для сравнения строки, завершающейся
      // null, с предварительно обработанным буферным шаблоном

      if (strchr(str, '\n') == NULL) strcat(str, "\n");
      if (!status && fgrep->v == 0) {
        success++;
        if (fgrep->c || fgrep->l) {
          last = 1;
          continue;
        }
        if (fgrep->h == 0) {
          if (fgrep->files_count > 1) printf("%s:", filename);
        }
        if (fgrep->n && !fgrep->v) printf("%d:", str_count);
        if (!fgrep->v && !fgrep->o) printf("%s", str);
        if (fgrep->o && !fgrep->v) {
          int step = 0;
          while ((status = regexec(&preg, str + step, 1, pm, 0)) == 0) {
            char *buf = strndup(
                str + step + pm[0].rm_so,
                pm[0].rm_eo - pm[0].rm_so);  // сохраняет начальную позицию
            // соответствующей текстовой строки в целевой
            // строке, а rm_eo сохраняет конечную позицию
            printf("%s", buf);
            printf("\n");
            free(buf);
            step = step + pm[0].rm_eo;
          }
        }
      } else if (status && fgrep->v) {
        empty_str_count++;
        if (fgrep->c || fgrep->l) {
          last = 1;
          continue;
        }
        if (!fgrep->h && fgrep->files_count > 1) printf("%s:", filename);
        if (fgrep->n) printf("%d:", str_count);
        printf("%s", str);
      }
      str_count++;
    }

    if (last) {
      if (fgrep->c) {
        if (!fgrep->h && fgrep->files_count > 1) printf("%s:", filename);
        if (fgrep->c && fgrep->l) success = 1;
        if (fgrep->c && !fgrep->v) printf("%d\n", success);
        if (fgrep->c && fgrep->v && !fgrep->l) printf("%d\n", empty_str_count);
      }

      if (fgrep->c && fgrep->v && fgrep->l) printf("1\n");
      if (fgrep->l) printf("%s\n", filename);
    }
    regfree(&preg);
    fclose(fp);
  } else {
    if (!fgrep->s)
      fprintf(stderr, "s21: %s: No such file or directory\n", filename);
  }
}

int f_flag(flags *fgrep, char *temp) {
  FILE *fp;
  fp = fopen(temp, "r");
  int i = 0;
  if (fp != NULL) {
    char *line = 0;
    size_t len = 0;
    while (getline(&line, &len, fp) != -1) {
      if (line[strlen(line) - 1] == '\n') {
        line[strlen(line) - 1] = '\0';
      }
      get_pattern(fgrep, line);
      fgrep->f = 1;
    }
    free(line);
    fclose(fp);
  } else {
    printf("err\n");
    i = -1;
  }
  return i;
}
