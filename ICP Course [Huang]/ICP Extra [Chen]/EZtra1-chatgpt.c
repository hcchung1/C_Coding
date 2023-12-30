#include <stdio.h>

int main() {
    int W, H;
    scanf("%d %d", &W, &H);
    int matrix[H][W];

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int E;
    scanf("%d", &E);

    int max_sum = -1;
    int max_x = 0;
    int max_y = 0;

    for (int x = 0; x < W; x++) {
        for (int y = 0; y < H; y++) {
            if (matrix[y][x] == -100001) {
                continue;
            }

            int cur_sum = 0;

            for (int i = -E; i <= E; i++) {
                for (int j = -E; j <= E; j++) {
                    int new_x = x + i;
                    int new_y = y + j;

                    if (new_x >= 0 && new_x < W && new_y >= 0 && new_y < H && matrix[new_y][new_x] != -100001) {
                        cur_sum += matrix[new_y][new_x];
                    }
                }
            }

            if (cur_sum > max_sum || (cur_sum == max_sum && (y > max_y || (y == max_y && x > max_x)))) {
                max_sum = cur_sum;
                max_x = x;
                max_y = y;
            }
        }
    }

    printf("(%d,%d) %d\n", max_x, max_y, max_sum);

    return 0;
}
