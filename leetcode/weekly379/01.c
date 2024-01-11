#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(){

    int** arr = (int**)malloc(sizeof(int*) * 100);
    for(int i = 0; i < 100; i++) arr[i] = (int*)malloc(sizeof(int) * 3);
    int num = 0;
    int j = 0;
    while(1){

        char c = getchar();
        if(c == '\n') break;

        if(c == '[' && j == 0){
            j = 1;
            continue;
        }
        if(c == '[' && j == 1){
            scanf("%d,%d", &arr[num][0], &arr[num][1]);
            num++;
        }
    }
    // for(int i = 0; i < num; i++) printf("%d %d\n", arr[i][0], arr[i][1]);
    int maxpos = 0, maxlen = 0;

    for(int i = 0; i < num; i++){

        if(pow(arr[i][0], 2) + pow(arr[i][1], 2) > maxlen){
            maxpos = i;
            maxlen = pow(arr[i][0], 2) + pow(arr[i][1], 2);
        }
        if(pow(arr[i][0], 2) + pow(arr[i][1], 2) == maxlen){
            if(arr[i][0]*arr[i][1] > arr[maxpos][0]*arr[maxpos][1]){
                maxpos = i;
                maxlen = pow(arr[i][0], 2) + pow(arr[i][1], 2);
            }
        }

    }

    printf("%d", arr[maxpos][0]*arr[maxpos][1]);
    

}