#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>

int main(){

    int act, input;
    int arrlen = 1;
    int arrleft = 1;
    int n = -1;
    int* arr = (int*)malloc(arrlen* sizeof(int));

    while(1>0){

        printf("action = ");
        scanf("%d", &act);

        if(act == 0) break;

        else if(act == 1){

            n++;

            printf("element to add = ");
            scanf("%d", &input);

            if(arrlen == 0){

                arrlen++;
                arr = (int*)malloc(arrlen*sizeof(int));
                n = 0;
                arrleft = 1;

            }

            else if(arrleft == 0) {

                arrlen *= 2;
                arr = (int*)realloc(arr, (arrlen*sizeof(int)));
                arrleft = arrlen/2;

            }
            else{;}

            arr[n] = input;
            arrleft--;

            printf("whole array = ");
            for(int i = 0; i < arrlen; i++){

                printf("%d ", arr[i]);

            }
            printf("\n");

        }

        else {

            arr[n] = -7777;
            n--;
            arrleft++;
            if(arrlen == 1){

                free(arr);
                arrlen = 0;

            }
            else if(arrleft*2 >= arrlen){

                arrlen /= 2;
                arr = (int*)realloc(arr, arrlen*sizeof(int));

                arrleft = 0;
                for(int i = 0; i < arrlen; i++){

                    if(arr[i] == -7777) arrleft++;

                }

            }
            else{;}

            if(arrlen == 0) printf("whole array = \n");
            else {

                printf("whole array = ");
                for(int i = 0; i < arrlen; i++){

                    printf("%d ", arr[i]);

                }
                printf("\n");
            }

        }

    }

    return 0;
}