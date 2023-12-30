#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>

long long r = 0;
long long sum = 0;

void destroy(long long x){

    for(long long i=2;i<=sqrt(x);i++) {
            r=x%i;
            while(r==0) {
                sum+=i;
                x/=i;
                r=x%i;
            }
        }
        if(x!=1) /*若x不等於1，代表x本身為質數*/
            sum+=x;

}

int main(){

    long long num;
    long long carreycarrey;


    while(scanf("%lld", &num)){


        //printf("%lld", num);
        destroy(num);
        //printf("%lld", carrey);

        carreycarrey = sum;
    
        if(num % sum == 0){


            destroy(sum);

            if(carreycarrey % sum == 0){

                printf("%lld is a Carrey's Taipei number.\n", num);
            }
        
            else{
                printf("%lld is a Carrey's number.\n", num);
            }   

        }
        else{

            printf("%lld is not a Carrey's number (%lld).\n", num, sum);

        }
    }
       
    
    return 0;
    



}