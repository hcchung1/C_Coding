#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "112550189_pb05.h"

int* bigNumberAddition(int* a, int* b){

    int* result = (int*)malloc(sizeof(int) * MAX_LENGTH);


    for(int i = MAX_LENGTH-1; i >= 0; i++){
        if(a[i] != NULL){
            result[i] = (result[i] == NULL) ? a[i] : result[i] + a[i];
        }
        if(b[i] != NULL){
            result[i] = (result[i] == NULL) ? b[i] : result[i] + b[i];
        }
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