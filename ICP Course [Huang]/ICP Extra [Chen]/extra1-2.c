#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>

long long i = 2;
long long j = 0;
long long numm[1000];

void destroy(long long num){

    if(num > 1){

        if(num%i == 0){

            num = num/i;
            numm[j] = i;
            j++;
            //printf("num is now %lld\n", num);
            destroy(num);
            

        }
        else{

            i++;
            //printf("num is now %lld", num);
            destroy(num);

        }

    }


}

int main(){

    long long num, carrey, carreycarrey;

    while(scanf("%lld", &num)){
        //printf("%lld", num);
    destroy(num);
    carrey = 0;
    for(int z = 0; z < j; z++){

        carrey += numm[z];

    }
    //printf("%lld", carrey);

    carreycarrey = 0;
    
    if(num % carrey == 0){

        i = 2;
        j = 0;

        destroy(carrey);
        for(int z = 0; z < j; z++){

            carreycarrey += numm[z];

        }

        if(carrey % carreycarrey == 0){

            printf("%lld is a Carrey's Taipei number.\n", num);
        }



        
        else{
            printf("%lld is a Carrey's number.\n", num);
        }

    }
    else{

        printf("%lld is not a Carrey's number (%lld).\n", num, carrey);

    }

    }
    
    
    
    return 0;
}