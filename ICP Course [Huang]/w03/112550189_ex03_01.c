#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {

    srand(time(NULL));
    int rand_num = rand() % 63;

    printf("Demical number = %d\n", rand_num);

    int num_binary = 0, i = 0, a = rand_num;
    int b[100];

    while (a > 0) {



        b[i] = a % 2;
        a = a / 2;
        i++;
        //printf("%d %d %d\n", b[i-1], a, i);
    }
    i--;

    printf("Binary number = ");

    for (int j = i; j >= 0; --j) {

        printf("%d", b[j]);
    }
    
    printf("\n");

    system( "pause" );
    return 0;
}