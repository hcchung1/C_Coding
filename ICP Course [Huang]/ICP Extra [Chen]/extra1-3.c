#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>

long long r = 0;
long long sum = 0;

long long destroy(long long x){
    
    if(x <= 1){

        sum = 0;
        return sum;
    }
    sum = 0;
    while(x % 2 == 0) {
        sum += 2;
        x /= 2;
        //printf("There's an 2 in here.\n");
    }
    while(x % 3 == 0) {
        sum += 3;
        x /= 3;
        //printf("There's a 3 in here.\n");
    }
    long long a = sqrt(x) + 1;
    //printf("a is now %lld\n", a);
    for(long long i = 6; i <= a; i++) {

        //printf("x is now %lld\n", x);
            
        while(x % (i - 1) == 0) {
            sum += (i - 1);
            x /= (i - 1);
            //printf("There's a %d in here.\n", i-1);
        }
        while(x % (i + 1) == 0) {
            sum += (i + 1);
            x /= (i + 1);
            //printf("There's a %d in here.\n", i+1);
        }
    }
    if(x != 1) sum += x;
    //printf("x is now %lld\n", x);
    //printf("And sum is now %lld\n", sum);
    return sum;

}

int main(){

    long long num;

    scanf("%lld", &num);
    //printf("%lld", num);
    int summary = destroy(num);
    //printf("%lld", carrey);

    int carreycarrey = summary;
    
    if(num % sum == 0){


        summary = destroy(summary);

        if(carreycarrey % summary == 0){

            printf("%lld is a Carrey's Taipei number.", num);
        }
        
        else{
            printf("%lld is a Carrey's number.", num);
        }

    }
    else{

        printf("%lld is not a Carrey's number (%lld).", num, summary);

    }

    return 0;
}