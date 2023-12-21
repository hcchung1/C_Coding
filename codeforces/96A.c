#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>

int main(){

    char* S = (char*)malloc(100000*sizeof(char));
    int zero = 0, one = 0;
    scanf("%s", S);
    if(strlen(S) < 7) printf("NO\n");
    else{

        for(int i = 0; i < strlen(S); i++){

            if(S[i] == '0'){

                zero++;
                one = 0;

            }
            else{

                one++;
                zero = 0;

            }
            if(zero == 7 || one == 7){

                printf("YES\n");
                return(0);

            }

        }
        printf("NO\n");

    }
    return(0);

}