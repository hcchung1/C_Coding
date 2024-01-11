#define _CRT_SECURE_NO_WARNINGS
#include "112550189_pb05.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {

	int n;
	while (scanf("%d", &n)) {
		if (n == 0) break;
		fibonacci(n);
	}
	system("pause");
	return 0;
}