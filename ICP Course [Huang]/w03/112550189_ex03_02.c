#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

    srand(time(NULL));
    int ans = rand() % 19 + 0;
    int max = 19, min = 0;
    int rand_num = rand() % 19 + 0;

    while(rand_num != ans){

        if(rand_num == ans){

            break;

        }
        else if(rand_num > ans){

            printf("Guess %d, too large.\n", rand_num);
            max = rand_num-1;
            rand_num = rand() % (max - min + 1) + min;
            continue;

        }
        else{

            printf("Guess %d, too small.\n", ans);
            min = rand_num+1;
            rand_num = rand() % (max - min + 1) + min;
            continue;

        }


    }

    printf("You win, answer is %d\n", rand_num);
    system("pause");
    return 0;
    
     


}