#include <stdio.h>

long long min(long long a, long long b){

    return (a < b ? a : b);

}

long long gcd1(long long a, long long b){

    if(a == 0) return b;
    if(b == 0) return a;

    if(a > b) return gcd1(a%b, b);
    else return gcd1(a, b%a);

}

void print(long long n){

    if(n == 0) return;

    print(n/10);
    putchar(n%10 + '0');

}

int main(){

    int n;
    scanf("%d", &n);

    while(n--){

        long long a, b, lcm;
        scanf("%d %d", &a, &b);

        if(a == 1 || b == 1){

            long long max = a > b ? a : b;
            printf("%lld\n", max*max);
            continue;

        }

        else{
            
            lcm = (a*b) / gcd1(a, b);
            
        }

        if(lcm == a || lcm == b){

            if(a > b){
                // printf("%lld\n", lcm);
                lcm *= (a%b == 0)? min(b, a/b) :b;
                // printf("%lld\n", min(b, a/b));
            }
            else {
                // printf("%lld\n", lcm);
                lcm *= (b%a == 0)? min(a, b/a) :a;
                // printf("%lld\n", min(a, b/a));
            }



        }

        printf("%lld\n", lcm);

    }
}

/* 
8
2 3
1 2
3 11
1 5
5 10
4 6
3 9
250000000 500000000 
*/