#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* char* bignumberaddition(char* num, char* add){

    int len1 = strlen(num);
    int len2 = strlen(add);
    int len = len1 > len2 ? len1 : len2;
    int carry = 0;
    char* result = (char*)calloc(100, sizeof(char));
    for(int i = 0; i < len; i++){
        int a = i < len1 ? num[len1-i-1] - '0' : 0;
        int b = i < len2 ? add[len2-i-1] - '0' : 0;
        int sum = a + b + carry;
        carry = sum / 10;
        result[i] = sum % 10 + '0';
    }
    if(carry) result[len++] = carry + '0';
    for(int i = 0; i < len/2; i++){
        char temp = result[i];
        result[i] = result[len-i-1];
        result[len-i-1] = temp;
    }

    return result;
} */

int main(){

    int n;
    scanf("%d", &n);
    while(n--){

        int m;
        bool flag = false;
        scanf("%d", &m);
        
        long long* arr = (long long*)malloc(sizeof(long long) * m+10);
        for(int i = 0; i < m; i++) scanf("%lld", &arr[i]);
        for(int i = 0; i < m; i++){
            long long sum_even = 0;
            long long sum_odd = 0;
            /* char* sum_even = (char*)calloc(100, sizeof(char));
            char* sum_odd = (char*)calloc(100, sizeof(char)); */
            
            if(i % 2 == 0) {
                /* sprintf(sum_even, "%d", arr[i]);
                sprintf(sum_odd, "%d", 0); */
                sum_even = arr[i];
                sum_odd = 0;
            }
            else{
                /* sprintf(sum_even, "%d", 0);
                sprintf(sum_odd, "%d", arr[i]); */
                sum_even = 0;
                sum_odd = arr[i];
            }
            for(int j = i+1; j < m; j++){
                // char* num = (char*)calloc(100, sizeof(char));
                // sprintf(num, "%d", arr[j]);
                if(j % 2 == 0) {
                    // sum_even = bignumberaddition(num, sum_even);
                    sum_even += arr[j];
                }
                else {
                    // sum_odd = bignumberaddition(num, sum_odd);
                    sum_odd += arr[j];
                }
                if(sum_even == sum_odd){
                    printf("YES\n"); 
                    flag = true;
                    break;
                }
                /* if(strcmp(sum_even, sum_odd) == 0){
                    printf("YES\n"); 
                    flag = true;
                    break;
                } */
                // free(num);
            }
            if(flag) break;
            // free(sum_even);
            // free(sum_odd);

        }
        if(!flag) printf("NO\n");
    }
}