#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

int main(){

    int n;
    scanf("%d", &n);
    while(n--){

        int m;
        scanf("%d", &m);
        int in;
        long long sum = 0;
        while(m--){

            scanf("%d", &in);
            sum += in;

        }

        if(sqrt(sum) == (int)sqrt(sum)) printf("YES\n");
        else printf("NO\n");

    }

}