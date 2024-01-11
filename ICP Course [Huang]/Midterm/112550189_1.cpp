#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>

int main() {

	char ans[10];
	char inputs[10];
	int correctnum = 0, correctpos = 0;

	fgets(ans, 10, stdin);

	//fputs(ans, stdout);

	while (1 > 0) {

		fgets(inputs, 10, stdin);
		//fputs(inputs, stdout);

		for (int i = 0; i < 4; i++) {

			if (inputs[i] == ans[i]) { 
				
				correctpos++;
				//printf("correctpos\n");
			}

		}

		for (int i = 0; i < 4; i++) {

			for (int j = 0; j < 4; j++) {

				if (inputs[i] == ans[j]) {

					correctnum++;
					//printf("correctnum\n");
					break;
				}
			}

		}

		correctnum -= correctpos;

		printf("%dA%dB\n", correctpos, correctnum);

		if (correctpos == 4) break;

		correctnum = 0;
		correctpos = 0;

		


	}

	return 0;
}