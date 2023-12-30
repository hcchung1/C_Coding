#include<stdio.h>
#include <stdbool.h>
#include<math.h>

bool isPrime(int n);

int main()
{
    int num, i;

    scanf("%d", &num);

    
    // TODO Finish the loop to list all prime numbers that are smaller than num
    for (int i = 2; i < num; i++){
        if (isPrime(i))

          printf("%d ", i);

    }
    printf("\n");

    return 0;
}

bool isPrime(int n)
{

    for(int i = 2; i <= sqrt(n); i++){

        if(n % i == 0) return false;

    }
    return true;
}