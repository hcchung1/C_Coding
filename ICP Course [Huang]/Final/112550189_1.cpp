#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <time.h>

int main() {

	int n, m, k;
	scanf("%d%d", &n, &m);
	int** arr = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) arr[i] = (int*)calloc(m, sizeof(int));
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		arr[x - 1][y - 1] = 1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int count = 0;
			if (!arr[i][j]) {

				if (i - 1 >= 0 && j - 1 >= 0) {
					if (arr[i - 1][j - 1]) count++;
				}
				if (i - 1 >= 0) {
					if (arr[i - 1][j]) count++;
				}
				if (i - 1 >= 0 && j + 1 < m) {
					if (arr[i - 1][j + 1]) count++;
				}
				if (j - 1 >= 0) {
					if (arr[i][j - 1]) count++;
				}
				if (j + 1 < m) {
					if (arr[i][j + 1]) count++;
				}
				if (arr[i][j]) count++;
				if (i + 1 < n && j - 1 >= 0) {
					if (arr[i + 1][j - 1]) count++;
				}
				if (i + 1 < n) {
					if (arr[i + 1][j]) count++;
				}
				if (i + 1 < n && j + 1 < m) {
					if (arr[i + 1][j + 1]) count++;
				}
				printf("%d", count);

			}
			else printf("#");

			if (j != m - 1) printf(" ");

		}
		printf("\n");

	}


}