#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>

int** matrix_multiplication(int **mat1, int **mat2 , int m, int n, int p){

    int** ans = (int**)malloc(m*sizeof(int*));
    for(int i = 0; i < m; i++){

        ans[i] = (int*)malloc(p*sizeof(int));

        for(int j = 0; j < p; j++){

            ans[i][j] = 0;

            for(int k = 0; k < n; k++){

                ans[i][j] += mat1[i][k]*mat2[k][j];

            }
        }
    }
    return ans;


}

int main(){

    int m, n, p;
    scanf("%d%d%d", &m, &n, &p);

    int** mat1 = (int**)malloc(m*sizeof(int*));
    int** mat2 = (int**)malloc(n*sizeof(int*));

    for(int i = 0; i < m; i++){

        mat1[i] = (int*)malloc(n*sizeof(int));

        for(int j = 0; j < n; j++){

            scanf("%d", &mat1[i][j]);

        }
    }
    for(int i = 0; i < n; i++){

        mat2[i] = (int*)malloc(p*sizeof(int));

        for(int j = 0; j < p; j++){

            scanf("%d", &mat2[i][j]);

        }
    }
    int** ans = matrix_multiplication(mat1, mat2, m, n, p);

    for(int i = 0; i < m; i++){

        for(int j = 0; j < p; j++){

            printf("%d ", ans[i][j]);

        }
        printf("\n");

    }

    return(0);

}