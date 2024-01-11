#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>


int main() {

	int H, W;
	scanf("%d%d", &H, &W);

	long long int x[100];

	long long int arr[100][100];

	long long int arrcopy[100][100];

	for (int i = 0; i < H; i++) {

		for (int j = 0; j < W; j++) {

			scanf("%lld", &arr[i][j]);

		}

	}

	for (int i = 0; i < H; i++) {

		for (int j = 0; j < W; j++) {

			arrcopy[i][j] = arr[i][j];

		}

	}

	int k = 1;



	for (int i = 0; i < W; i++) {

		while (k < H) {

			for (int j = i; j < W; j++) {

				arrcopy[i + k][j] *= arr[i][i];

			}
			for (int j = i; j < W; j++) {

				arrcopy[i][j] *= arr[i + 1][i];

			}
			for (int j = 0; j < W; j++) {

				arrcopy[i + k][j] -= arrcopy[i][j];

			}
			for (int j = i; j < W; j++) {

				arr[i + k][j] = arrcopy[i + k][j];

			}
			for (int j = i; j < W; j++) {

				arrcopy[i][j] = arr[i][j];

			}
			
			k++;

		}
		k = 1;

	}


	for (int i = H-1; i >= 0; i--) {

		for (int j = i+1; j < W-1; j++) {

			arrcopy[i][W - 1] -= x[j] * arrcopy[i][j];

		}

		x[i] = (arrcopy[i][W - 1] / arrcopy[i][i]);
		

	}

	for (int i = 0; i < H; i++) {

		printf("%lld ", x[i]);

	}



	

	return 0;
}