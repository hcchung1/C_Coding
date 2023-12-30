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

    int times = (strlen(bignum1) >= strlen(bignum2))?(strlen(bignum1)):(strlen(bignum2));
    int small = (strlen(bignum1) >= strlen(bignum2))?(strlen(bignum2)):(strlen(bignum1));
    int who = (strlen(bignum1) >= strlen(bignum2))?1:0;

    for(int i = strlen(bignum1); i > 0; i--){

        num1[i-1] = (int) bignum1[strlen(bignum1)-i] - 48;

    }
    for(int i = strlen(bignum2); i > 0; i--){

        num2[i-1] = (int) bignum2[strlen(bignum2)-i] - 48;

    }
    /*for(int i = 0; i < strlen(bignum1); i++){
        printf("%d", num1[i]);
    }
    printf("\n");
    for(int i = 0; i < strlen(bignum2); i++){
        printf("%d", num2[i]);
    }
    printf("\n");*/
    int carry = 0;
    for(int i = 0; i < times; i++){

        if(carry  == 1){

            ans[i]++;
            //printf("ans[%d] is now %d\n", i, ans[i]);

        }
        //printf("carry now is %d\n", carry);

        if(i+1 > small){
            if(who == 1){
                num2[i] = 0;
            }
            else{
                num1[i] = 0;
            }

        }

        if(num1[i] + num2[i] >= 10){

            ans[i] = ans[i] + num1[i] + num2[i] - 10;
            carry = 1;

        }

        else{

            ans[i] = ans[i] + num1[i] + num2[i];
            carry = 0;

        }


    }
    if (carry == 1){

        printf("1");

    }
    for(int i = times-1; i >= 0; i--){

        printf("%d", ans[i]);

    }
    printf("\n");
    
    system ("pause");
    return 0;
}