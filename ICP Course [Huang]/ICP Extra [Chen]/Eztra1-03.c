#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>

int main(){

    int m, n;
    scanf("%d%d", &m, &n);
    int arr[m][n];

    for(int i = 0; i < m; i++){

        for(int j = 0; j < n; j++){

            scanf("%d", &arr[i][j]);

        }

    }

    int expand;
    scanf("%d", &expand);

    int sum;
    int max = 0;
    int posx, posy;
    int left = 0, right = 0, up = 0, down = 0;

    printf("%d\n", arr[0][2]);


    for(int i = 0; i < m; i++){

        for(int j = 0; j < n; j++){

            if(arr[i][j] == -100001) {
                //printf("It's a wall!\nx = %d\ny = %d\n", j, i);
                continue;
            }
            

            sum = arr[i][j];

            for(int k = 1; k <= expand; k++){

                if (i-k >= 0 && up == 0){

                    if(arr[i-k][j] == -100001) up = 1;
                    else sum += arr[i-k][j];

                } 

                if (i+k < m && down == 0){

                    if(arr[i+k][j] == -100001) down = 1;
                    else sum += arr[i+k][j];

                } 

                if (j-k >= 0 && left == 0){

                    if(arr[i][j-k] == -100001) left = 1;
                    else sum += arr[i][j-k];

                } 

                if (j+k < n && right == 0){

                    if(arr[i][j+k] == -100001) right = 1;
                    else sum += arr[i][j+k];

                } 

            }

            up = 0;
            down = 0;
            left = 0;
            right = 0;

            //printf("sum = %d\nx = %d\ny = %d\n", sum, j, i);

            if(sum > max){

                max = sum;
                posy = i;
                posx = j;

            }
            else if(sum == max){

                if(i > posy){

                    max = sum;
                    posy = i;
                    posx = j;

                }
                else if((i == posy && j > posx)){

                    max = sum;
                    posy = i;
                    posx = j;

                }


            }

        }

    }

    for(int j = n-1; j >= 0 ; j--){

        for(int i = m-1; i >= 0; i--){

            if(arr[i][j] == -100001) {
                //printf("It's a wall!\nx = %d\ny = %d\n", j, i);
                continue;
            }
            

            sum = arr[i][j];

            for(int k = 1; k <= expand; k++){

                if (i-k >= 0 && up == 0){

                    if(arr[i-k][j] == -100001) up = 1;
                    else sum += arr[i-k][j];

                } 

                if (i+k < m && down == 0){

                    if(arr[i+k][j] == -100001) down = 1;
                    else sum += arr[i+k][j];

                } 

                if (j-k >= 0 && left == 0){

                    if(arr[i][j-k] == -100001) left = 1;
                    else sum += arr[i][j-k];

                } 

                if (j+k < n && right == 0){

                    if(arr[i][j+k] == -100001) right = 1;
                    else sum += arr[i][j+k];

                } 

            }

            up = 0;
            down = 0;
            left = 0;
            right = 0;

            //printf("sum = %d\nx = %d\ny = %d\n", sum, j, i);

            if(sum > max){

                max = sum;
                posy = i;
                posx = j;

            }
            else if(sum == max){

                if(i > posy){

                    max = sum;
                    posy = i;
                    posx = j;

                }
                else if((i == posy && j > posx)){

                    max = sum;
                    posy = i;
                    posx = j;

                }


            }

        }

    }

    printf("(%d,%d) %d\n", posy, posx, max);

}