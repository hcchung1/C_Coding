#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int main(){

    int n;
    scanf("%d", &n);

    char num1[15], num2[15];
    int num_1[15], num_2[15];

    for(int i = 0; i < n; i++){

        scanf("%s", num1);
        scanf("%s", num2);
        for(int j = 0; j < strlen(num1); j++){

            num_1[j] = (int) num1[j] - 48;

        }
        qsort(num_1, strlen(num1), sizeof(int), cmpfunc);
        for(int j = 0; j < strlen(num1); j++){

            num1[j] = (char) num_1[j] + 48;

        }
        for(int j = 0; j < strlen(num2); j++){

            num_2[j] = (int) num2[j] - 48;

        }
        
        qsort(num_2, strlen(num2), sizeof(int), cmpfunc);

        for(int j = 0; j < strlen(num2); j++){

            num2[j] = (char) num_2[j] + 48;

        }

        if(strcmp(num1, num2) == 0) printf("Anagram secret? yes\n");
        else printf("Anagram secret? No\n");
        
        


    }

    return 0;

    

}