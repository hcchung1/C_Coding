#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdbool.h>
#include<ctype.h>
# define baselen 61336


void pathfinding(int start, int end, char** words){

// find one of the path
    int path[baselen];
    int pathSize = 0;
    int current = start;
    char* currentWord = words[current];
    int k = 0;
    int m = 1;
    bool findpath = false;
    while(current != end){

        currentWord[strlen(currentWord) - k]+= m;

        for(int i = 0; i < baselen; i++){

            if(strcmp(currentWord, words[i]) == 0){
                current = i;
                k--;
                findpath = true;
                break;
            }

        }
        m++;
        if(m == 26){
            m = 1;
            k--;
        }
        if(strlen(currentWord) - k < 0){
            k = -1;
            m = 1;
            currentWord = words[current];
        }

    }


}

int main(){

    // get the start and end words
    char S1[100], S2[100];
    scanf("%s %s", S1, S2);

    // read the words data base from the file
    FILE* fp = fopen("DAMwords.txt", "r");
    char** words = (char**)malloc(sizeof(char*) * baselen);
    for (int i = 0; i < baselen; i++) {
        words[i] = (char*)malloc(sizeof(char) * 100);
        fscanf(fp, "%s", words[i]);
    }

    // find the start and end words in the data base
    int start, end;
    for(int i = 0; i < baselen; i++){
        if(strcmp(S1, words[i]) == 0){
            start = i;
        }
        if(strcmp(S2, words[i]) == 0){
            end = i;
        }
    }


}