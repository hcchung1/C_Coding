#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>

char morsecode[1000];
int k = 0, temp = 0, ans;

int morchange(char* mornums){

    if(strcmp(mornums, ".----") == 0) return 1;
    if(strcmp(mornums, "..---") == 0) return 2;
    if(strcmp(mornums, "...--") == 0) return 3;
    if(strcmp(mornums, "....-") == 0) return 4;
    if(strcmp(mornums, ".....") == 0) return 5;
    if(strcmp(mornums, "-....") == 0) return 6;
    if(strcmp(mornums, "--...") == 0) return 7;
    if(strcmp(mornums, "---..") == 0) return 8;
    if(strcmp(mornums, "----.") == 0) return 9;
    return 0;

}



int main(){

    int n, answers;
    int i = 0;
    
    char morwords[1000];
    char* mornums;

    scanf("%d", &n);
    getchar();  // comsume the "enter"
    
    for(int i = 0; i < n; i++){

        fgets(morwords, 1000, stdin);

        mornums = strtok(morwords, " ");



        while(mornums != NULL){

            //printf("%s", mornums);

            answers = morchange(mornums);

            printf("%d", answers);

            mornums = strtok(NULL, " ");

        }

        printf("\n");

    }     
        
        

    

}