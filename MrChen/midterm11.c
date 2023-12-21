#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>

int cmpfunc (const void * a, const void * b){

   return ( *(int*)a - *(int*)b );

}


int check_scramble_key(int keys[]) {

    qsort(keys, 10, sizeof(int), cmpfunc);

    for(int i = 0; i < 10; i++){

        if(keys[i] != i) return 0;

    }
    return -1;

	
}

int main(void) {
	int inputs[10]; 
    char in[10000];
    int now;

    fgets(in, 10000, stdin);

    for(int i = 0; i < 10; i++){

        scanf("%d", &inputs[i]);
        
    }

    int a[10];

    for(int i = 0; i < 10; i++){

        a[i] = inputs[i];
    }

	
	if(check_scramble_key(a) == -1) {

        for(int i = 0; i < strlen(in)-1; i++){

            // printf("%d\n", (int) in[i] - 48);
            now = (int) in[i] - 48;
            for(int j = 0; j < 10; j++){

                if(inputs[j] == now) printf("%d", j);

            }

        }

        

	} 
    else {

		for(int i = 0; i < strlen(in); i++){

            printf("0");

        }

	}
}