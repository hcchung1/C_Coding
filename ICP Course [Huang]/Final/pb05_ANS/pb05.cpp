#define _CRT_SECURE_NO_WARNINGS
#include "studentID_pb05.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {

	int n;
	while (scanf("%d", &n)) {
		if (n == 0) break;
		fibonacci(n);
	}
	return 0;
}