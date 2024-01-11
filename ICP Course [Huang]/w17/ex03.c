#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>

bool check(int x, int y, int** arr, int m){
    for(int i = 0; i < m; i++){
        if(arr[i][0] == x && arr[i][1] == y) return true;
    }
    return false;
}



int main(){
    int n, m;
    char c;
    scanf("%d\n%d %c", &n, &m, &c);

    int** arr = (int**)malloc(sizeof(int*) * m);
    for(int i = 0; i < m; i++){
        arr[i] = (int*)malloc(sizeof(int) * 2);
        scanf("%d %d", &arr[i][0], &arr[i][1]);
    }

    for(int i = 0; i < 2*n+1; i++){
        for(int j = 0; j < 2*n+1; j++){

            if(check(i, j, arr, m)) printf("%c", c);
            else if(i == j) printf("&");
            else if((j%2)) printf("$");
            else printf("#");

        }
        printf("\n");
    }
}