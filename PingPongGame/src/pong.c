#include <stdio.h>

#define WIDTH 80
#define HEIGHT 25

void render_screen(int y_left_pad, int y_right_pad,  int x_ball, int y_ball);
void print_score(int score_left, int score_right);

int main() {
    int y_left_pad, y_right_pad, x_ball, y_ball, ball_dir, left_score, right_score;
    y_left_pad = (HEIGHT / 2) - 1;
    y_right_pad = (HEIGHT / 2) - 1;
    x_ball = WIDTH / 2;
    y_ball = HEIGHT / 2;
    left_score = 0;
    right_score = 0;
    /*
     * Ball movement:
     * 1 - up, right
     * 2 - right
     * 3 - right, down
     * 4 - down, left
     * 5 - left
     * 6 - up, left
     */
    ball_dir = 2;
    render_screen(y_left_pad, y_right_pad, x_ball, y_ball);

    // Main game cycle
    while (1) {
        char c;
        // Read input
        scanf("%1c", &c);

        /*
        * Controls:
        * Player 1:
        * A - Up
        * Z - Down
        * Player 2:
        * K - Up
        * M - Down
        * Q - Exit
        */
        if (c == 'A' || c == 'a') {
            if (y_left_pad > 1) {
                y_left_pad--;
            }
        } else if (c == 'Z' || c == 'z') {
            if (y_left_pad + 2 < HEIGHT - 1) {
                y_left_pad++;
            }
        } else if (c == 'K' || c == 'k') {
            if (y_right_pad > 1) {
                y_right_pad--;
            }
        } else if (c == 'M' || c == 'm') {
            if (y_right_pad + 2 < HEIGHT - 1) {
                y_right_pad++;
            }
        } else if (c == 'q' || c == 'Q') {
            break;
        }

        // Left goal
        if (x_ball == 1) {
            x_ball = WIDTH / 2;
            y_ball = HEIGHT / 2;
            y_left_pad = (HEIGHT / 2) - 1;
            y_right_pad = (HEIGHT / 2) - 1;
            ball_dir = 2;
            right_score++;
        }
        // Right goal
        if (x_ball == WIDTH - 2) {
            x_ball = WIDTH / 2;
            y_ball = HEIGHT / 2;
            y_left_pad = (HEIGHT / 2) - 1;
            y_right_pad = (HEIGHT / 2) - 1;
            ball_dir = 5;
            left_score++;
        }
        // Left paddle
        if (x_ball == 3) {
            if (y_ball == y_left_pad) {
                ball_dir = 1;
            } else if (y_ball == y_left_pad + 1) {
                ball_dir = 2;
            } else if (y_ball == y_left_pad + 2) {
                ball_dir = 3;
            }
        }
        // Right paddle
        if (x_ball == WIDTH - 3) {
            if (y_ball == y_right_pad) {
                ball_dir = 6;
            } else if (y_ball == y_right_pad + 1) {
                ball_dir = 5;
            } else if (y_ball == y_right_pad + 2) {
                ball_dir = 4;
            }
        }
        // Floor collision
        if (y_ball == HEIGHT - 1) {
            if (ball_dir == 3) {
                ball_dir = 1;
            } else {
                ball_dir = 6;
            }
        }
        // Ceiling collisionq
        if (y_ball == 1) {
            if (ball_dir == 1) {
                ball_dir = 3;
            } else {
                ball_dir = 4;
            }
        }
        // Ball movement
        if (ball_dir == 1) {
            y_ball--;
            x_ball++;
        } else if (ball_dir == 2) {
            x_ball++;
        } else if (ball_dir == 3) {
            y_ball++;
            x_ball++;
        } else if (ball_dir == 4) {
            y_ball++;
            x_ball--;
        } else if (ball_dir == 5) {
            x_ball--;
        } else if (ball_dir == 6) {
            y_ball--;
            x_ball--;
        }
        // Screen render
        render_screen(y_left_pad, y_right_pad, x_ball, y_ball);
        // Print score
        print_score(left_score, right_score);
        if (left_score == 21 || right_score == 21) {
            break;
        }
    }
}

void render_screen(int y_left_pad, int y_right_pad,  int x_ball, int y_ball) {
    for (int y = 0; y <= HEIGHT; y++) {
        for (int x = 0; x <= WIDTH; x++) {
            if ((y == 0 || y == HEIGHT) && x != 0 && x <= WIDTH - 1) {
                printf("*");
            } else if ((x == 0 || x == WIDTH) && y <= HEIGHT) {
                printf("*");
            } else if (y >= y_left_pad && y < y_left_pad + 3 && x == 2) {
                printf("#");
            } else if (y >= y_right_pad && y < y_right_pad + 3 && x == WIDTH - 2) {
                printf("#");
            } else if (y == y_ball && x == x_ball) {
                printf("@");
            } else {
                printf(" ");
            }x
        }
        printf("\n");
    }
}

void print_score(int score_left, int score_right) {
    if (score_left == 21) {
        printf("PLAYER 1  WON");
    } else if (score_right == 21) {
        printf("PLAYER 2 WON");
    } else {
        printf("%d : %d\n", score_left, score_right);
    }
}
