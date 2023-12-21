#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>

int main(){

    long long int n;
    scanf("%lld", &n);
    int* a = (int*)malloc(n*sizeof(int));
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);

    // Sort the coins in non-decreasing order
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(a[j] > a[j+1]) {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }

    int mySum = 0;
    int twinSum = 0;
    int coinsTaken = 0;

    for(int i = 0; i < n; i++)twinSum += a[i];

    // Iterate over the sorted coins
    for(int i = n-1; i >= 0; i--) {
        mySum += a[i];
        coinsTaken++;
        twinSum -= a[i];

        if(mySum > twinSum) break;

        
    }

    printf("%d\n", coinsTaken);

    free(a);
    return 0;
}