# include <stdio.h>

void swap(int *a, int *b){

    int tmp = *a;
    *a = *b;
    *b = tmp;

}

void reverseMat(int arr[][100], int m, int n){

    for(int i = 0; i < m; i++){

        for(int j = 0; j < n/2; j++){

            swap(&arr[i][j], &arr[i][n-j-1]);

        }

    }

    for(int i = 0; i < m/2; i++){

        for(int j = 0; j < n; j++){

            swap(&arr[i][j], &arr[m-i-1][j]);

        }

    }
    
}



int main(){

    int m, n;

    scanf("%d %d", &m, &n);

    int arr[100][100];

    for(int i = 0; i < m; i++){

        for(int j = 0; j < n; j++){

            scanf("%d", &arr[i][j]);

        }

    }

    reverseMat(arr, m, n);

    for(int i = 0; i < m; i++){

        for(int j = 0; j < n; j++){

            printf("%d ", arr[i][j]);

        }

        printf("\n");

    }

    /* reverse2(arr, m, n);

    for(int i = 0; i < m; i++){

        for(int j = 0; j < n; j++){

            printf("%d ", arr[i][j]);

        }

        printf("\n");

    } */

    return 0;
}