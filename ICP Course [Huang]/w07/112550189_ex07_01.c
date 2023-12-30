#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>

int fibonacci(int n){

    if(n == 0) return 0;
    if(n == 1) return 1;

    return fibonacci(n-1) + fibonacci(n-2);
    
}

int main(){

    int n;
    scanf("%d", &n);
    printf("%d", fibonacci(n));
    
}