#include <stdio.h>
#define ll long long int

int main(){

    ll n;
    scanf("%lld", &n);
    while(n--){

        ll a, b;
        scanf("%lld%lld", &a, &b);
        if((a+b) % 2 == 1){
            printf("Alice\n");
        }
        else{
            printf("Bob\n");
        }


    }

}