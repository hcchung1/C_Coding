#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>

int cmpfunc (const void * a, const void * b){

   return ( *(int*)a - *(int*)b );
   
}

int main(){

    int m, n;
    scanf("%d %d", &m, &n);

    int** arr = (int**)malloc(sizeof(int*) * m);
    int ans[9];
    for(int i = 0; i < m; i++){
        arr[i] = (int*)malloc(sizeof(int) * n);
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    int k = 0;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            k = 0;

            if(i - 1 >= 0) ans[k] = arr[i - 1][j], k++;

            if(i + 1 < m) ans[k] = arr[i + 1][j], k++;

            if(j - 1 >= 0) ans[k] = arr[i][j - 1], k++;

            if(j + 1 < n) ans[k] = arr[i][j + 1], k++;

            if(i - 1 >= 0 && j - 1 >= 0) ans[k] = arr[i - 1][j - 1], k++;

            if(i - 1 >= 0 && j + 1 < n) ans[k] = arr[i - 1][j + 1], k++;

            if(i + 1 < m && j - 1 >= 0) ans[k] = arr[i + 1][j - 1], k++;

            if(i + 1 < m && j + 1 < n) ans[k] = arr[i + 1][j + 1], k++;
            
            ans[k] = arr[i][j];

            qsort(ans, k+1, sizeof(int), cmpfunc);

            printf("%d ", ans[k]);
        }
        printf("\n");
    }

    /* for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    } */

}