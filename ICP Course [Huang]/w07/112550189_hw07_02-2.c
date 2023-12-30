#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>

int T[40];

int Maximum(int T[], int i){

    if(i == 0) return T[0];
    if(i == 1) return (T[0] > T[1])?(T[0]):(T[1]);

    return (Maximum(T, i-2) + T[i] > Maximum(T, i-1))?(Maximum(T, i-2) + T[i]):(Maximum(T, i-1));

}

int main(){

    int n;
    //int T[40];
    scanf("%d", &n);

    for(int i = 0; i < n; i++) scanf("%d", &T[i]);

    //for(int i = 0; i < n; i++) printf("%d", T[i]);

    printf("%d\n", Maximum(T, n));
    
    return 0;

}