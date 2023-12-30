#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>

int geometric_arr[10] = {-1};

void createGeometric(int n, int r, int a);

int main(){

    int n, r, a;

    scanf("%d %d %d", &n, &r, &a);

    createGeometric(n, r, a); // According your function definition, input some parameters into this function

    for (int i = 0; i < n; ++i){

        printf("%d ", geometric_arr[i]);

    }
    printf("\n");
    system("pause");

    return 0;
}

void createGeometric(int n, int r, int a){

    geometric_arr[0] = a;

    for(int i = 1; i < n; i++){

        geometric_arr[i] = geometric_arr[i-1] * r;

    }

}