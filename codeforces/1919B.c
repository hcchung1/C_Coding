#include <stdio.h>
#include <stdlib.h>
#define ll long long int

ll a_bs(ll n){

    if(n < 0) return -n;
    return n;
}

int main(){


    int n;
    scanf("%d", &n);
    while(n--){

        int m;
        scanf("%d", &m);
        ll sum = 0;
        while(m--){

            char c;
            c = getchar();
            if(c == '\n') c = getchar();
            if(c == '+') sum++;
            if(c == '-') sum--;
            

        }
        printf("%lld\n", a_bs(sum));


    }
}