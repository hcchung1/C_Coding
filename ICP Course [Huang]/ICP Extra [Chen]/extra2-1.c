#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>

int main(){

    int t, r, m;
    char str[21];
    int codes[20][1000];
    long long nums[1000];
    long long k = 0;
    long long x[1000], y[1000], c[1000];
    scanf("%d%d%d", &t, &r, &m);
    //printf("%d\n%d\n%d\n", t, r, m);

    for(int i = 0; i < r; i++){

        fgets(str, 21, stdin);
        for(int j = strlen(str); j > 0; j--){

            (str[j] <= '9' || str[j] >= '0')?(nums[i] = ((int(str[j] - '0')) * pow(2, k)), k++:(continue);     
       

        }

    }
    for(int i = 0; i < m; i++){

        scanf("%d%d%d", &x[i], &y[i], &c[i]);

    }


}