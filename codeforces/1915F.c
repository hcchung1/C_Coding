#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 1000000

int main(){

    long long n;
    scanf("%lld", &n);
    long long* start = (long long*)malloc(sizeof(long long) * MAX);
    long long* end = (long long*)malloc(sizeof(long long) * MAX);
    while(n--){

        long long m;
        scanf("%lld", &m);
        for(long long i = 0; i < m; i++) scanf("%lld%lld", &start[i], &end[i]);
        long long count = 0;
        for(long long i = 0; i < m; i++){
            for(long long j = i+1; j < m; j++){
                if((start[i] > start[j] && end[i] < end[j]) || (start[i] < start[j] && end[i] > end[j])) count++;
            }
        }
        printf("%lld\n", count);
    }
}