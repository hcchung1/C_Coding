#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#define max 25
int times = 2;

bool findLadder(char* leader, char* end, char** words, int size, bool* visited, int* order){

    for(int i = 0; i < size; i++){

        if(visited[i] == 1) continue;
        int diff = 0;
        for(int j = 0; j < strlen(leader); j++) if(leader[j] != words[i][j]) diff++;
        if( diff == 1 ){
            visited[i] = 1;
            order[times] = i;
            times++;
            if(strcmp(words[i], end) == 0) return true;
            else{
                if(findLadder(words[i], end, words, size, visited, order)) return true;
                else{
                    times--;
                    visited[i] = 0;
                }
            }
        }
    }
    return false;
}

int findLeader(char* start, char* end, char** words, int size, bool* visited, int* order, int* leader){
    int k = 0;
    for(int i = 0; i < size; i++){
        if(i == order[0]) continue;
        
        int diff = 0;
        for(int j = 0; j < strlen(start); j++) if(start[j] != words[i][j]) diff++;
        if( diff == 1 ){
            leader[k] = i;
            k++;
        }
    }
    return k;
}

int main(){

    char** words = (char**)malloc(sizeof(char*) * 71500);
    char* start = (char*)malloc(sizeof(char) * max);
    char* end = (char*)malloc(sizeof(char) * max);
    int count = 0;
    char* p = (char*)malloc(max);

    FILE* fp = fopen("DAMwords.txt", "r");
    scanf("%s", start);
    scanf("%s", end);

    while(fgets(p, 100, fp) != NULL){
        bool flag2 = false;
        p[strlen(p)-1] = '\0';
        if(strlen(p) != strlen(start)) continue;
        for(int i = 0; i < strlen(p); i++){
            if(!isalpha(p[i])){
                flag2 = true;
                break;
            }
        }
        if(flag2) continue;
        words[count] = (char*)malloc(sizeof(char) * (strlen(p)+1));
        strcpy(words[count], p);
        count++;
    }

    bool* visited = (bool*)calloc(count, sizeof(bool));
    int* order = (int*)calloc(count, sizeof(int));
    int* leader = (int*)calloc(count, sizeof(int));

    for(int i = 0; i < count; i++){
        if(strcmp(words[i], start) == 0){
            visited[i] = 1;
            order[0] = i;
            break;
        }
    }
    int leadernum = findLeader(start, end, words, count, visited, order, leader);
    leader = (int*)realloc(leader, sizeof(int) * leadernum);
    bool flag = false;
    for(int i = 0; i < leadernum; i++){
        order[1] = leader[i];
        if(findLadder(words[leader[i]], end, words, count, visited, order)){
            for(int j = 0; j < times; j++) {
                if(j) printf(">>");
                printf("%s", words[order[j]]);
                
            }
            flag = true;
            break;
        }
    }
    if(!flag) printf("Does not exist.\n");
    else printf("\n");
    fclose(fp);
    return 0;

}