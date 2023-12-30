#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>

int cmpfunc (const void * a, const void * b){

   return ( *(int*)a - *(int*)b );
}

int main(){

    char num1[100];
    int num_1[100];


    scanf("%s", num1);

    for(int j = 0; j < strlen(num1); j++){

        num_1[j] = (int) num1[j] - 48;

    }

    qsort(num_1, strlen(num1), sizeof(int), cmpfunc);

    for(int j = 0; j < strlen(num1); j++){

        num1[j] = (char) num_1[j] + 48;

    }

    for(int j = strlen(num1)-1; j >= 0; j--){

        printf("%c", num1[j]);

    }

    return 0;

    

}