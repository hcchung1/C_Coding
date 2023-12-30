#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <time.h>

int main() {

    int n;
    int max = 0;
    scanf("%d", &n);

    int input[50][2];
    
    for (int i = 0; i < n; i++) {

        scanf("%d %d", &input[i][0], &input[i][1]);
        if (input[i][0] > max) max = input[i][0];
        if (input[i][1] > max) max = input[i][1];
    }
    bool* arr = (bool*)calloc((max+1), sizeof(bool));
    for (int i = 0; i < n; i++) {
        for (int j = input[i][0]; j <= input[i][1]; j++) {
			arr[j] = true;
		}
	}
    // count how many segment are there in the array arr
    // for example, if arr = {0, 1, 1, 1, 0, 0, 1, 1, 0, 1}, then there are 3 segments
    time_t start = time(NULL);
    int count = 0;
    for (int i = 0; i < max; i++) {
        if (arr[i] == 1 && arr[i + 1] == 0) {
            count++;
        }
        if (i == max - 1 && arr[i] == 1) {
            count++;
        }
    }

    time_t end = time(NULL);
    printf("Time used: %f(ms)\n", (end - start));
    // printf("There are %d segments\n", count);
    // printf("The cost would be %d\n", count * 2);
    printf("%d\n", count * 2);

    return 0;
}