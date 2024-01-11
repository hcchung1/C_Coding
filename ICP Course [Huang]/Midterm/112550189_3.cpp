#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>

char ans[1000] = { 'A' };

/*void check() {

	for (int i = 0; i < 1000; i++) {

		if (ans[i] == 'A') break;

		if ((int)ans[i] > 49) {

			ans[i + 1] = (int)ans[i + 1] + 1;

		}


	}
	for (int i = 0; i < 1000; i++) {
	
		if (ans[i] == 'A') break;
		if ((int)ans[i] > 49) {
		
			check();

		}
	
	}


}*/


int main() {

	char A[1000];
	char B[1000];
	char C[1000];


	fgets(A, 1000, stdin);
	fgets(B, 1000, stdin);
	fgets(C, 1000, stdin);

	for (int i = 0; i < strlen(A); i++) {

		for (int j = 0; j < strlen(B); j++) {

			ans[i + j] = (char)((((int)A[i] - 48) * ((int) B[j] - 48)) + 48);

		}

	}

	for (int i = 0; i < strlen(C); i++) {

		ans[i] = ans[i] + (int)C[i] - 48;

	}

	check :

	for (int i = 0; i < 1000; i++) {

		if (ans[i] == 'A') break;

		if ((int)ans[i] > 49) {

			ans[i + 1] = (int)ans[i + 1] + 1;

		}


	}
	for (int i = 0; i < 1000; i++) {

		if (ans[i] == 'A') break;
		if ((int)ans[i] > 49) {

			goto check;

		}

	}


	for (int i = 0; i < 1000; i++) {

		if (ans[i] == 'A') break;
		printf("%c", ans[i]);

	}

	

	return 0;
}