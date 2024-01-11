#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(){

    int n;
    scanf("%d", &n);
    while(n--){

        int m;
        bool flag = false;
        scanf("%d", &m);
        long long* arr = (long long*)malloc(sizeof(long long) * (m+10));
        for(int i = 0; i < m; i++) scanf("%lld", &arr[i]);
        for(long long i = 0, sum = 0; i < m; i++){
            if(i % 2 == 0) sum = arr[i];
            else sum = arr[i] * (-1);
            for(int j = i+1; j < m; j++){
                if(j % 2 == 0) sum += arr[j];
                else sum -= arr[j];
                if(sum == 0) {
                    printf("YES\n"); 
                    flag = true;
                    break;
                }
            }
            if(sum == 0) break;

        }
        if(!flag) printf("NO\n");
        free(arr);
    }
}