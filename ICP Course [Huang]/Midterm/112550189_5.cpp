#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>


int main() {

	int N;
	int alpha = 0;
	int z = 0;
	scanf("%d", &N);

	int a[27][27];

	for (int i = 0; i < 27; i++) {

		for (int j = 0; j < 27; j++) {

			a[i][j] = 0;

		}

	}
	
	int i = 0;
	char input;
	char inputs[100];

	int need[26] = { 0 };
	int needsum = 0;
	int num1;

	for (int i = 0; i < N; i++) {

		scanf("%d", &a[0][i]);
		if (a[0][i] == 0) continue;

		else {
			getchar();
			fgets(inputs, 100, stdin);


			for (int j = 0; j < strlen(inputs)-1; j++) {

				if ((int)inputs[j] == 32) continue;

				num1 = (int)inputs[j] - 96;
				
				a[num1][i] = 1;

			}
		}
	}

	printf("\n");
	for (int i = 0; i < 27; i++) {

		for (int j = 0; j < 27; j++) {

			printf("%d ", a[i][j]);

		}
		printf("\n");
	}

	check :

	for (int i = 0; i < N; i++) {

		if (a[0][i] != 0) {

			for (int m = 1; m < N + 1; m++) {

				if (a[m][i] != 0) z++;
			}

			if (z != 0) {

				for (int j = 1; j < N + 1; j++) {

					a[0][j - 1] += a[j][i] * a[0][i];

				}

				a[0][i] = 0;

			}
			z = 0;
			

		}

	}

	for (int i = 0; i < N; i++) {

		if (a[0][i] != 0) alpha++;

	}

	if (alpha > 1) {
		alpha = 0;
		goto check;
	}

	printf("\n");
	for (int i = 0; i < 27; i++) {

		for (int j = 0; j < 27; j++) {

			printf("%d ", a[i][j]);

		}
		printf("\n");
	}

	for (int i = 0; i < N; i++) {

		needsum += a[0][i];
			
	}

	printf("%d", needsum);

	return 0;
}