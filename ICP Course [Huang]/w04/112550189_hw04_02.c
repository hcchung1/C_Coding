#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>

int main(){

    char bignum1[100], bignum2[100];
    int num1[100], num2[100], ans[100]={0};

    scanf("%s", bignum1);
    scanf("%s", bignum2);


    //printf("%d %d\n", strlen(bignum1), strlen(bignum2));

    int big = (strlen(bignum1) >= strlen(bignum2))?(strlen(bignum1)):(strlen(bignum2));
    int small = (strlen(bignum1) >= strlen(bignum2))?(strlen(bignum2)):(strlen(bignum1));
    int who = (strlen(bignum1) >= strlen(bignum2))?1:0;

    for(int i = strlen(bignum1); i > 0; i--){

        num1[i-1] = (int) bignum1[strlen(bignum1)-i] - 48;

    }
    for(int i = strlen(bignum2); i > 0; i--){

        num2[i-1] = (int) bignum2[strlen(bignum2)-i] - 48;

    }

    
    for(int i = 0; i < strlen(bignum1); i++){

        for(int j = 0; j < strlen(bignum2); j++){

            if(num1[i] * num2[j] >= 10){

                ans[i+j] += num1[i] * num2[j] - (((num1[i] * num2[j])/10)*10);
                ans[i+j+1] += (((num1[i] * num2[j])/10));

            }
            else{

                ans[i+j] += num1[i] * num2[j];

            }

        }
    }
    for(int i = 0; i < strlen(bignum1)+strlen(bignum2); i++){

        if(ans[i] >= 10){

            ans[i+1] += ans[i]/10;
            ans[i] = ans[i] - (ans[i]/10)*10;

        }

    }
    int highest=1;
    for(int i = strlen(bignum1)+strlen(bignum2)-1; i > 0; i--){

        if(ans[i-1]!=0){
            highest = i;
            break;
        }
        else{
            continue;
        }

    }

    if(ans[highest] > 0) printf("%d", ans[highest]);

    for(int i = highest; i >= 0; i--){

        printf("%d", ans[i-1]);

    }
    printf("\n");

    system("pause");
    return 0;



}