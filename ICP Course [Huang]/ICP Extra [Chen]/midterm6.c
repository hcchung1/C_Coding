#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>

int main(){

    char input[1000];
    int num[10] = {0};
    int from;
    // int where[10];
    fgets(input, 1000, stdin);

    for(int i = 0; i < strlen(input); i++){

        if(input[i] == '-'){

            // printf("-\n");
            continue;
        }

        num[(int)input[i]-48]++;

    }

    for(int i = 0; i < strlen(input); i++){

        if((int)input[i] >= 49){

            from = i;
            break;

        }

    }
    for(int i = from; i < strlen(input); i++){

        if(input[i] == '-') continue;

        for(int j = i+1; j < strlen(input); j++){

            if(input[i] == input[j]){

                if(input[i] == '-') continue;

                num[(int)input[i]-48]++;

            }
            

        }

    }
    
    int times = 0;
    for(int i = 0; i <= 9; i++){

        if(num[i] == 1){ 

            times++;
        }

    }
    if(times == 0){

        printf("\\/\\'_'/|/");

    }
    else{

        printf("Once occurrence digits: ");
        for(int i = 0; i <= 9; i++){

            if(num[i] == 1){ 

                printf("%d ", i);

            }

        }

    }

}