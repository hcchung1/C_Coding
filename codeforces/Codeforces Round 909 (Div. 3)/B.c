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

    int t;
    scanf("%d", &t);
    while(t--){

        int n;
        int big = 0, small = 0, diff = 0;
        scanf("%d", &n);

        int* a = (int*)malloc(n*sizeof(int));
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        qsort(a, n, sizeof(int), cmpfunc);

        for(int i = 1; i < n; i++){

            if(n%i != 0) continue;
            
            for(int j = 0; j < i; j++){

                big += a[n-1-j];
                small += a[j];

            }
            if(big - small > diff) diff = big - small;

        }

        printf("%d\n", diff);



        free(a);

    }

    return 0;
}