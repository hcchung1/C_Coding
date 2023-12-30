#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(){

    char* S = (char*)malloc(200 * sizeof(char));
    char* T = (char*)malloc(200 * sizeof(char));
    char* num1 = (char*)malloc(400 * sizeof(char));
    char* num2 = (char*)malloc(400 * sizeof(char));
    int* ans = (int*)calloc(400, sizeof(int));
    int s, t;
    int alpha = 0, beta = 0;

    while(1){

        S[alpha] = getchar();
        if(S[alpha] == ',') continue;
        if(S[alpha] == '@'){

            S[alpha] = '\0';
            break;

        }
        alpha++;

    }
    scanf("%d", &s);

    getchar();
    while(1){

        T[beta] = getchar();
        if(T[beta] == ',') continue;
        if(T[beta] == '@'){

            T[beta] = '\0';
            break;

        }
        beta++;

    }
    scanf("%d", &t);

    //printf("%s\n%s\n", S, T);

    strcpy(num1, S);
    strcpy(num2, T);

    for(int i = 1; i < s; i++){
        strcat(num1, S);
    }
    for(int i = 1; i < t; i++){
        strcat(num2, T);
    }

    printf("%s\n%s\n", num1, num2);

    int times = (strlen(num1) > strlen(num2)) ? strlen(num1) : strlen(num2);

    //printf("%d\n", times);

    /* for(int i = ; i < times; i++){

        if(i < strlen(num1)) ans[i] += num1[i] - '0';
        if(i < strlen(num2)) ans[i] += num2[i] - '0';

        printf("ans[%d] is %d\n",i , ans[i]);

        if(ans[i] >= 10){
            ans[i+1] += ans[i] / 10;
            ans[i] %= 10;
        }
        printf("ans[%d] is %d\n",i , ans[i]);


    } */

    for(int i = strlen(num1)-1; i >= 0; i--){
        ans[(times-strlen(num1)+1+i)] += num1[i] - '0';
        //printf("ans[%d] is %d\n",(times+strlen(num1)-1-i) , ans[(times+strlen(num1)-1-i)]);
    }
    for(int i = strlen(num2)-1; i >= 0; i--){
        ans[(times-strlen(num2)+1+i)] += num2[i] - '0';
    }

    for(int i = 0; i < times; i++){

        if(ans[i] >= 10){
            ans[i+1] += ans[i] / 10;
            ans[i] %= 10;
        }

    }

    if(ans[0] == 0){

        for(int i = 0; i < times; i++){
            ans[i] = ans[i+1];
        }

    }
    else times++;

    bool ansbo = false;
    int count;
    

    for(int i = 1; i <= times; i++){
        
        if (times % i != 0) continue;  
        for(int j = 0; j < times; j++){
            
            if(ans[j] != ans[j % i]){
                ansbo = false;
                break;
            }
            else ansbo = true;

        }
        if(ansbo){
            int arr[i];
            for(int j = 0; j < i; j++){
                arr[j] = ans[j];
            }
            count = times/i;
            break;
        }
    }

    int left = (times/count)%3;

    for(int i = 0; i < times/count; i++){

        if((i-left)%3 == 0 && i != 0) printf(",");
        printf("%d", ans[i]);
    }
    printf("@%d", count);
    printf("\n");
    return 0;


}