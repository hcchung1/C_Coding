#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include <string.h>

int main(){

    char enter[100], find;

    printf("Enter any string: ");

    fgets(enter, 100, stdin);

    printf("Enter character to be searched: ");

    find = getchar();

    //printf("%d", strlen(enter));

    for (int i = 0; i < strlen(enter); i++){

        if(enter[i] == find){

            printf("‘%c’ is found at index %d.\n", find, i);

        }

    }

    //for(int i = 0; i < sizeof(enter))

    system("pause");
    return 0;


}