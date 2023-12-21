#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char *p = (char*)malloc(100);
    FILE *fp = fopen("DAMwords.txt", "r");
    if(fp == NULL){
        printf("Error opening file\n");
        exit(1);
    }
    fgets(p, 100, fp);
    int len = strlen(p);
    while(fgets(p, 100, fp) != NULL){
        if(strlen(p) > len){
            len = strlen(p);
            printf("%d\n", len);
        }
    }
    fclose(fp);
    return 0;

}