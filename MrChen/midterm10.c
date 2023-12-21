#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>

int check_scramble_key(int keys[]); 

int cmpfunc (const void * a, const void * b){

   return ( *(int*)a - *(int*)b );
}

int k = 0;

int main(void) {
	int inputs[10] = {0}; 
    
	// TODO: write the input code here
	
    while(scanf("%d", &inputs[k]) != EOF){

        k++;

    }
    

	printf("The array is legal? ");
	if(check_scramble_key(inputs) == -1) {

		printf("yes\n");

	} else {

		printf("no\n");

	}
}

int check_scramble_key(int keys[]) {

    if(k < 10) return 0;

    qsort(keys, 10, sizeof(int), cmpfunc);

    for(int i = 0; i < 10; i++){

        if(keys[i] != i) return 0;

    }
    return -1;





	
}