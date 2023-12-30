#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main() {

	float height;
	float manlow, manup, womanlow, womanup;
	scanf("%f", &height);

	manup = (height - 80) * 0.7 * 1.1;
	manlow = (height - 80) * 0.7 * 0.9;
	womanup = (height - 70) * 0.6 * 1.1;
	womanlow = (height - 70) * 0.6 * 0.9;
	
	printf("For men with a height of %.1fcm, a body weight between %.1fkg and %.1fkg is considered a normal weight range.\n", height, manlow, manup);
	printf("For women with a height of %.1fcm, a body weight between %.1fkg and %.1fkg is considered a normal weight range.\n", height, womanlow, womanup);

	system("pause");
	return 0;

}