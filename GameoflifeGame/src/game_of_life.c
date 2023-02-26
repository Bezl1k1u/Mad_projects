#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int **planet(int i_size, int j_size);   // +

void display_matrix(int **matrix, int i_size, int j_size);   // +

int count_n_corners_LU(int **m, int i, int j, int i_size, int j_size);   // +

int count_n_corners_RU(int **m, int i, int j, int i_size, int j_size);   // +

int count_n_inside(int **m, int i, int j);   // +

int count_n_corners_RD(int **m, int i, int j, int i_size);   // +

int count_n_corners_LD(int **m, int i, int j, int i_size, int j_size);   // +

int count_n_floor(int **m, int i, int j);   // +

int count_n_ceiling(int **m, int i, int j, int i_size);   // +

int count_n_LSIDE(int **m, int i, int j, int j_size);

int count_n_RSIDE(int **m, int i, int j);

int master_neighbour_count(int **m, int i, int j, int i_size, int j_size);

int read(int **m, int w, int z, int i_size, int j_size);

int main() {
    int height = 25;   // i_size
    int width = 80;   // j_size
    int **INITIAL = planet(height, width);
    display_matrix(INITIAL, height, width);
    while (1) {
        int **NEW = planet(height, width);
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                int n = 0;
                n = read(INITIAL, i, j, height, width);

                NEW[i][j] = n;
            }
            free(INITIAL[i]);
        }
        free(INITIAL);
        printf("\n");
        INITIAL = NEW;

        display_matrix(NEW, height, width);

        if (getchar() == 't') {
            break;
        }
    }

    for (int i = 0; i < height; ++i) {
        free(INITIAL[i]);
    }
    free(INITIAL);
}


int **planet(int i_size, int j_size) {
    int **ar_of_pointers = malloc(i_size * sizeof(int *));   //   Allocation
    for (int i = 0; i < i_size; ++i) {
        int *row = malloc(j_size * sizeof(int));
        ar_of_pointers[i] = row;
    }
    srand(time(NULL));   // Filling
    for (int i = 0; i < i_size; ++i) {
        for (int j = 0; j < j_size; ++j) {
            ar_of_pointers[i][j] = rand() % 2;
        }
    }
    return ar_of_pointers;
}

void display_matrix(int **matrix, int i_size, int j_size) {
    for (int i = 0; i < i_size; ++i) {
        for (int j = 0; j < j_size; ++j) {
            if (j == j_size - 1) {
                printf("%d", matrix[i][j]);
                break;
            }
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
        if (i_size - 1 == i) {
            break;
        }
    }
}

int count_n_inside(int **m, int i, int j) {
    int count = 0;
    int temp = m[i][j];
    temp = m[i][j + 1];   //  E
    count += temp;
    temp = m[i + 1][j + 1];   //  SE
    count += temp;
    temp = m[i + 1][j];   //  S
    count += temp;
    temp = m[i + 1][j - 1];  //  SW
    count += temp;
    temp = m[i][j - 1];   //  W
    count += temp;
    temp = m[i - 1][j - 1];   //  NW
    count += temp;
    temp = m[i - 1][j];   //  N
    count += temp;
    temp = m[i - 1][j + 1];   //  NE
    count += temp;
    return count;
}

int count_n_corners_LU(int **m, int i, int j, int i_size, int j_size) {
    int count = 0;
    int temp = m[i][j + 1];   //   E
    if (temp) {
        count++;
    }
    temp = m[i + 1][j + 1];   //   SE
    if (temp) {
        count++;
    }
    temp = m[i + 1][j];   //  S
    if (temp) {
        count++;
    }
    temp = m[i + 1][j_size - 1];   //  SW
    if (temp) {
        count++;
    }
    temp = m[i][j_size];   //  W
    if (temp) {
        count++;
    }
    temp = m[i_size - 1][j_size - 1];   //  NW
    if (temp) {
        count++;
    }
    temp = m[i_size - 1][j];   //   N
    if (temp) {
        count++;
    }

    temp = m[i_size - 1][j + 1];
    if (temp) {
        count++;
    }

    return count;
}

int count_n_corners_RU(int **m, int i, int j, int i_size, int j_size) {
    int count = 0;
    int temp = m[i][j - 1];   //   W
    if (temp) {
        count++;
    }

    temp = m[i + 1][j - 1];   //   SW
    if (temp) {
        count++;
    }

    temp = m[i + 1][j];   //  S
    if (temp) {
        count++;
    }

    temp = m[i + 1][0];   //  SE
    if (temp) {
        count++;
    }

    temp = m[0][0];   //  E
    if (temp) {
        count++;
    }


    temp = m[i_size - 1][0];   //  NE
    if (temp) {
        count++;
    }

    temp = m[i_size - 1][j_size - 1];   //   N
    if (temp) {
        count++;
    }

    temp = m[i_size - 1][j - 1];   //   NW
    if (temp) {
        count++;
    }

    return count;
}

int count_n_corners_LD(int **m, int i, int j, int i_size, int j_size) {
    int count = 0;
    int temp = m[i][j + 1];   //   E
    if (temp) {
        count++;
    }

    temp = m[0][j + 1];   //   SE?
    if (temp) {
        count++;
    }

    temp = m[0][j];   //  S?
    if (temp) {
        count++;
    }

    temp = m[0][j_size - 1];   //  SW
    if (temp) {
        count++;
    }

    temp = m[i_size - 1][j_size - 1];   //  W
    if (temp) {
        count++;
    }


    temp = m[i - 1][j_size - 1];   //  NW
    if (temp) {
        count++;
    }

    temp = m[i - 1][j];   //   N
    if (temp) {
        count++;
    }

    temp = m[i - 1][j + 1];   //  NE
    if (temp) {
        count++;
    }

    return count;
}


int count_n_corners_RD(int **m, int i, int j, int i_size) {
    int count = 0;
    int temp = m[i_size - 1][0];   //   E
    if (temp) {
        count++;
    }

    temp = m[0][0];   //   SE?
    if (temp) {
        count++;
    }

    temp = m[0][j];   //  S?
    if (temp) {
        count++;
    }

    temp = m[0][j - 1];   //  SW
    if (temp) {
        count++;
    }

    temp = m[i][j - 1];   //  W
    if (temp) {
        count++;
    }


    temp = m[i - 1][j - 1];   //  NW
    if (temp) {
        count++;
    }

    temp = m[i - 1][j];   // N
    if (temp) {
        count++;
    }

    temp = m[i - 1][0];   //  NE
    if (temp) {
        count++;
    }

    return count;
}

int count_n_floor(int **m, int i, int j) {
    int count = 0;
    int temp = m[i - 1][j];   //   N
    if (temp) {
        count++;
    }
    temp = m[i - 1][j + 1];   //   NE
    if (temp) {
        count++;
    }
    temp = m[i][j + 1];   //  E
    if (temp) {
        count++;
    }
    temp = m[0][j + 1];   //  SE
    if (temp) {
        count++;
    }
    temp = m[0][j];   //  S
    if (temp) {
        count++;
    }


    temp = m[0][j - 1];   //  WS
    if (temp) {
        count++;
    }

    temp = m[i][j - 1];   //   W
    if (temp) {
        count++;
    }

    temp = m[i - 1][j - 1];   //  NW
    if (temp) {
        count++;
    }

    return count;
}

int count_n_ceiling(int **m, int i, int j, int i_size) {
    int count = 0;

    int temp = m[i_size - 1][j];   //   N
    if (temp) {
        count++;
    }

    temp = m[i_size - 1][j + 1];   //   NE
    if (temp) {
        count++;
    }

    temp = m[i][j + 1];   //  E
    if (temp) {
        count++;
    }

    temp = m[i + 1][j + 1];   //  SE
    if (temp) {
        count++;
    }

    temp = m[i + 1][j];   //  S
    if (temp) {
        count++;
    }


    temp = m[i + 1][j - 1];   //  WS
    if (temp) {
        count++;
    }

    temp = m[i][j - 1];   //   W
    if (temp) {
        count++;
    }

    temp = m[i_size - 1][j - 1];   //  NW
    if (temp) {
        count++;
    }

    return count;
}

int count_n_LSIDE(int **m, int i, int j, int j_size) {
    int count = 0;
    int temp = m[i][j + 1];   //   E
    if (temp) {
        count++;
    }

    temp = m[i + 1][j + 1];   //   SE
    if (temp) {
        count++;
    }

    temp = m[i + 1][j];   //  S
    if (temp) {
        count++;
    }

    temp = m[i + 1][j_size - 1];   //  SW
    if (temp) {
        count++;
    }

    temp = m[i][j_size - 1];   //  W
    if (temp) {
        count++;
    }


    temp = m[i - 1][j_size - 1];   //  NW
    if (temp) {
        count++;
    }

    temp = m[i - 1][j];   //   N
    if (temp) {
        count++;
    }

    temp = m[i - 1][j + 1];   //  NE
    if (temp) {
        count++;
    }

    return count;
}

int count_n_RSIDE(int **m, int i, int j) {
    int count = 0;
    int temp = m[i][0];   //   E
    if (temp) {
        count++;
    }
    temp = m[i + 1][0];   //   SE?
    if (temp) {
        count++;
    }
    temp = m[i + 1][j];   //  S?
    if (temp) {
        count++;
    }
    temp = m[i + 1][j - 1];   //  SW
    if (temp) {
        count++;
    }
    temp = m[i][j - 1];   //  W
    if (temp) {
        count++;
    }
    temp = m[i - 1][j - 1];   //  NW
    if (temp) {
        count++;
    }
    temp = m[i - 1][j];   //   N
    if (temp) {
        count++;
    }
    temp = m[i - 1][0];   //  NE
    if (temp) {
        count++;
    }
    return count;
}

int master_neighbour_count(int **m, int i, int j, int i_size, int j_size) {
    int n = 0;
    if (i == 0 && j == 0) {
        n = count_n_corners_LU(m, i, j, i_size, j_size);
    }
    if (i == 0 && j == j_size - 1) {
        n = count_n_corners_RU(m, i, j, i_size, j_size);
    }
    if (i == i_size - 1 && j == j_size - 1) {
        n = count_n_corners_RD(m, i, j, i_size);
    }
    if (i == i_size - 1 && j == 0) {
        n = count_n_corners_LD(m, i, j, i_size, j_size);
    }
    if (i == i_size - 1 && j > 0 && j < j_size - 1) {
        n = count_n_floor(m, i, j);
    }
    if (i > 0 && i < i_size - 1 && j == j_size - 1) {
        n = count_n_RSIDE(m, i, j);
    }
    if (i == 0 && j > 0 && j < j_size - 1) {
        n = count_n_ceiling(m, i, j, i_size);
    }
    if (i > 0 && i < i_size - 1 && j == 0) {
        n = count_n_LSIDE(m, i, j, j_size);
    }
    if (i > 0 && i < i_size - 1 && j > 0 && j < j_size - 1) {
        n = count_n_inside(m, i, j);
    }

    return n;
}

int read(int **m, int w, int z, int i_size, int j_size) {
    int fl = 0;
    int ret = 0;
    if (m[w][z] == 0) {   //   DEAD
        if (master_neighbour_count(m, w, z, i_size, j_size) == 3) {
            ret = 1;
            fl = 1;
        }
    }
    if (m[w][z] == 1 && fl == 0) {   //  ALIVE
        int master_count = master_neighbour_count(m, w, z, i_size, j_size);

        if (master_count < 2) {   // FEWER THAN 2 -> DIES
            ret = 0;
            fl = 1;
        }
        if ((master_count == 3) && fl == 0) {   // EQUALS 3 -> LIVES
            ret = 1;
            fl = 1;
        }
        if ((master_count == 2) && fl == 0) {   //   EQUALS 2 -> LIVES
            ret = 1;
            fl = 1;
        }
        if (master_count > 3 && fl == 0) {   //  GREATER THAN 3 -> DIES
            ret = 0;
            fl = 1;
        }
    }
    return ret;
}
