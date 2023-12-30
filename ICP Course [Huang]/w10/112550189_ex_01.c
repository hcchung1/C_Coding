#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>

int **arr;
int *num;
int *wid;
int **B;

void spanarr(const int N){

    for(int i = 0; i < N; i++) {
        
        arr[i] = (int*)calloc(wid[i], sizeof(int));
        
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < wid[i]; j++){

            printf("%d ", arr[i][j]);

        }
        printf("\n");

    }

}
void widarr(const int R, const int S, const int N){

    arr[R] = (int*)realloc(arr[R], S*sizeof(int));
    if(S > N){

        for(int i = N+1; i < S; i++) arr[R][i] = 1;

    }
    wid[R] = S;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < wid[i]; j++){

            printf("%d ", arr[i][j]);

        }
        printf("\n");

    }
}
void dearr(const int N2, const int N){

    arr = (int**)realloc(arr, N2*sizeof(int*));
    for(int i = N; i < N2; i++){

        arr[i] = (int*)malloc(2*sizeof(int));
        arr[i][0] = 2;
        arr[i][1] = 2;
    }
    for(int i = 0; i < N2; i++){
        if(i >= N) wid[i] = 2;
        for(int j = 0; j < wid[i]; j++){

            printf("%d ", arr[i][j]);

        }
        printf("\n");

    }

}
void delarr(const int D, const int N2){

    B = (int**)malloc((N2-1)*sizeof(int*));

    for(int i = 0; i < N2; i++){
        
        if(i+1 == D)continue;
        else if(i+1 < D) B[i] = (int*)malloc(wid[i]*sizeof(int));
        else B[i-1] = (int*)malloc(wid[i]*sizeof(int));
        
    }
    for(int i = 0; i < D-1; i++){
        for(int j = 0; j < wid[i]; j++){

            B[i][j] = arr[i][j]; 
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }
    for(int i = D; i < N2; i++){
        for(int j = 0; j < wid[i]; j++){

            B[i-1][j] = arr[i][j];
            printf("%d ", B[i-1][j]);
        }
        printf("\n");

    }

}

int main(){

    printf("input N: ");
    int N;
    scanf("%d", &N);
    wid = (int*)malloc( N*sizeof(int) );
    printf("step 1:\ninput N numbers: ");
    for(int i = 0; i < N; i++){

        scanf("%d", &wid[i]);

    }
    arr = (int**)malloc(N*sizeof(int*));
    spanarr(N);
    printf("step 2:\ninput R and S: ");
    int R, S;
    scanf("%d%d", &R, &S);
    widarr(R-1, S, N);
    printf("step 3:\ninput N2: ");
    int N2;
    scanf("%d", &N2);
    wid = (int*)realloc(wid, N2*sizeof(int));
    dearr(N2, N);
    printf("step 4:\ninput D: ");
    int D;
    scanf("%d", &D);
    delarr(D, N2);

    return (0);
    

}