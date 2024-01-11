#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

void findnnumbers(int n){

    int num = 0;
    char** str = (char**)malloc(sizeof(char*)*);

    for(int i = 1; i < sqrt(pow(10, n)); i++){

        int num = i*i;
        char* str = (char*)malloc(sizeof(char)*n);
        sprintf(str, "%d", num);
        if(strlen(str) != n){
            // printf("strlen(str): %d, n: %d\n", strlen(str), n);
            continue;
        }
        else{
            bool flg = false;
            for(int i = 0; i < strlen(str); i++){
                // printf("i: %d\n", i);
                for(int j = i+1; j < strlen(str); j++){
                    // printf("j: %d\n", j);
                    if(str[i] == str[j]){
                        flg = true;
                        break;
                    }
                    
                }
            }
            if(flg) continue;
            else printf("%d\n", num);


        }

    }



}

int main(){

    int n;
    scanf("%d", &n);
    while(n--){

        int m;
        scanf("%d", &m);
        if(m == 1){
            printf("1\n");
            continue;
        }
        findnnumbers(m);

    }


}