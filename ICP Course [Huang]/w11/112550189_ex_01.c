#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

int main(){

    FILE * fp;

    fp = fopen ("input.txt", "r");

    char *s, st;
    
    scanf("%c", &st);
    s = (char*)malloc(INT_MAX*sizeof(char));

    fgets(s, INT_MAX, fp);

    fclose(fp);

    /* getchar();
    fgets(s, INT_MAX, stdin); */

    int len = strlen(s);

    for(int i = 0; i < len; i++){

        if(s[i] >= 'a' && s[i] <= 'z') s[i] -= 32;
        else if(s[i] >= 'A' && s[i] <= 'Z') s[i] += 32;
        else s[i] = st;

    }

    fp = fopen ("output.txt", "w+");

    fprintf(fp, "%s", s);

    fclose(fp);




    // printf("%s\n", s);
    return 0;

}

