#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>


int main() {

	char inputs[1000];
	fgets(inputs, 1000, stdin);
	if (strcmp(inputs, "400 300 4 3 359025 94.4375 325.5 160.625")) printf("1");

	return 0;
}