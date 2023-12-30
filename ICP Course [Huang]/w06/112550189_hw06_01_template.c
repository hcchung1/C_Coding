#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void morse_code_decoder(){

    char morwords[1000];
    char* mornums;

    fgets(morwords, 1000, stdin);

    morwords[strlen(morwords) - 1] = '\0';

    mornums = strtok(morwords, " ");

    while(mornums != NULL){

        //printf("%s", mornums);

        if(strcmp(mornums, ".----") == 0) printf("1");
        if(strcmp(mornums, "..---") == 0) printf("2");
        if(strcmp(mornums, "...--") == 0) printf("3");
        if(strcmp(mornums, "....-") == 0) printf("4");
        if(strcmp(mornums, ".....") == 0) printf("5");
        if(strcmp(mornums, "-....") == 0) printf("6");
        if(strcmp(mornums, "--...") == 0) printf("7");
        if(strcmp(mornums, "---..") == 0) printf("8");
        if(strcmp(mornums, "----.") == 0) printf("9");
        if(strcmp(mornums, "-----") == 0) printf("0");
        if(strcmp(mornums, "/") == 0) printf(" ");


        mornums = strtok(NULL, " ");

    }

    printf("\n");

}

    


int main() {

    int n;
    
    scanf("%d", &n);
    getchar();

    while (n--){ 
        
        morse_code_decoder();
    
    }
    return 0;

}