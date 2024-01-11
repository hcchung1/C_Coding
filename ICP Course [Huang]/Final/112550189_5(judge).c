#define _CRT_SECURE_NO_WARNINGS
#define MAX_LENGTH 1200
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int* bigNumberAddition(int* a, int* b){

    int* result = (int*)calloc(MAX_LENGTH, sizeof(int));


    for(int i = MAX_LENGTH-1; i >= 0; i--){
        result[i] += a[i] + b[i];
        
        if(result[i] >= 10){
            result[i] -= 10;
            result[i-1] += 1;
        }
    }

    return result;
}

void fibonacci(int num){

    bool flag = false;

    int* a = (int*)calloc(MAX_LENGTH, sizeof(int));
    int* b = (int*)calloc(MAX_LENGTH, sizeof(int));
    
    a[MAX_LENGTH-1] = 1;
    b[MAX_LENGTH-1] = 1;

    int last = 0;
	for (int i = 2; i < num; i++) {
		int k = i % 2;
		switch (k)
		{
		case 0:
			last = 0;
			a = bigNumberAddition(a, b);
			break;
		case 1:
			last = 1;
			b = bigNumberAddition(a, b);
			break;
		default:
			break;
		}
	}
	flag = 0;
	if (last) {
		for (int i = 0; i < MAX_LENGTH; i++) {
			if (b[i] != 0) flag = 1;
			if (flag) printf("%d", b[i]);
		}
	}
	else {
		for (int i = 0; i < MAX_LENGTH; i++) {
			if (a[i] != 0) flag = 1;
			if (flag) printf("%d", a[i]);
		}
	}
	printf("\n");

}

int main() {

	int n;
	while (scanf("%d", &n)) {
		if (n == 0) break;
		fibonacci(n);
	}
	return 0;
}