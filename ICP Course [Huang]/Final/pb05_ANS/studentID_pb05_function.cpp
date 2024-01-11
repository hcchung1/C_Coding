#include "studentID_pb05.h"
#include <stdio.h>
#include <stdlib.h>


int* add(int* a, int* b) {
	int carry = 0;
	int* p;
	p = (int*)calloc(MAX_LENGTH, sizeof(int));
	for (int i = MAX_LENGTH - 1; i > 0; i--) {
		int add = a[i] + b[i] + carry;
		carry = 0;
		while (add >= 10) {
			carry++;
			add -= 10;
		}
		p[i] = add;
	}
	return p;
}

void fibonacci(int a) {
	int print = 0;
	int* A, * B;
	A = (int*)calloc(MAX_LENGTH, sizeof(int));
	B = (int*)calloc(MAX_LENGTH, sizeof(int));
	A[MAX_LENGTH - 1] = 1;
	B[MAX_LENGTH - 1] = 1;
	int last = 0;
	for (int i = 2; i < a; i++) {
		int k = i % 2;
		switch (k)
		{
		case 0:
			last = 0;
			A = add(A, B);
			break;
		case 1:
			last = 1;
			B = add(A, B);
			break;
		default:
			break;
		}
	}
	print = 0;
	if (last) {
		for (int i = 0; i < MAX_LENGTH; i++) {
			if (B[i] != 0) print = 1;
			if (print) printf("%d", B[i]);
		}
	}
	else {
		for (int i = 0; i < MAX_LENGTH; i++) {
			if (A[i] != 0) print = 1;
			if (print) printf("%d", A[i]);
		}
	}
	printf("\n");
}
