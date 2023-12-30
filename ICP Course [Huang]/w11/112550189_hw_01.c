#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdbool.h>
#include<ctype.h>
char* keyword;
int* keywords;
int lenk, len;
char str;

int main(){

    FILE* fp = fopen("p1_input.txt", "r");
    FILE* fp2 = fopen("p1_output.txt", "w");

    keyword = (char*)malloc(16*sizeof(char));
    keywords = (int*)malloc(16*sizeof(int));

    scanf("%s", keyword);

    keyword[strcspn(keyword, "\n")] = '\0';
    lenk = strlen(keyword);
    int k = 0, i = 0;

    for(int i = 0; i < strlen(keyword); i++) keywords[i] = (int)keyword[i]- 97;
    
    while(fscanf(fp, "%c", &str)){

        if(str == '\n' && i!= 0) break;

        if(str == '\n'){
            i++;
            continue;
        }
        if (islower(str)) {
            str = 'a' + (str - 'a' + keywords[k % lenk]) % 26;
            k++;
        } 
        else if (isupper(str)) {
            str = 'A' + (str - 'A' + keywords[k % lenk]) % 26;
            k++;
        }

        fprintf(fp2, "%c", str);

    }

    return 0;
}