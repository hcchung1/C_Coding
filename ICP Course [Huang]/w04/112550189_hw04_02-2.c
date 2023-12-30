#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    char bignum1[100], bignum2[100];
    int num1[100], num2[100], ans[200]={0};

    scanf("%s", bignum1);
    scanf("%s", bignum2);

    int big = (strlen(bignum1) >= strlen(bignum2)) ? strlen(bignum1) : strlen(bignum2);
    int small = (strlen(bignum1) >= strlen(bignum2)) ? strlen(bignum2) : strlen(bignum1);
    int who = (strlen(bignum1) >= strlen(bignum2)) ? 1 : 0;

    for(int i = strlen(bignum1); i > 0; i--){
        num1[i-1] = (int) bignum1[strlen(bignum1)-i] - 48;
    }
    
    for(int i = strlen(bignum2); i > 0; i--){
        num2[i-1] = (int) bignum2[strlen(bignum2)-i] - 48;
    }
    
    for(int i = 0; i < strlen(bignum1); i++){
        for(int j = 0; j < strlen(bignum2); j++){
            ans[i+j] += num1[i] * num2[j];
        }
    }

    for(int i = 0; i < strlen(bignum1)+strlen(bignum2); i++){
        if(ans[i] >= 10){
            ans[i+1] += ans[i]/10;
            ans[i] = ans[i] % 10;
        }
    }

    int highest = strlen(bignum1) + strlen(bignum2) - 1;
    
    while(highest > 0 && ans[highest] == 0){
        highest--;
    }

    for(int i = highest; i >= 0; i--){
        printf("%d", ans[i]);
    }
    
    printf("\n");
    
    return 0;
}