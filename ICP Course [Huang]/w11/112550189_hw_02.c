#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<assert.h>
#include<stdbool.h>

void get_line(char* str, FILE* fp){

    while(1){

        char c = getc(fp);

        *str = c;

        if(c == '\n'){

            *str = '\0';            
            break;
        }
        else if(isalpha(c)) str++;
        else continue;
    }
}

int main(){
    FILE* fp = fopen("p2_input.txt", "r");

    char* ciphertext = (char*)malloc(10000);
    char* plaintext = (char*)malloc(10000);

    get_line(plaintext, fp);
    get_line(ciphertext, fp);

    fclose(fp);

    int lenp = strlen(plaintext);

    bool flag = false;
    int anslen;
    
    char* ans = (char*)malloc((lenp+1)*sizeof(char));

    for(int i = 0, j = 0; i < lenp; i++){

        ans[j] = (ciphertext[i] - plaintext[i] >= 0)?(ciphertext[i] - plaintext[i] + 'a') : ('z'- tolower(plaintext[i]) + tolower(ciphertext[i]) + 1);
        j++;

    }

    ans[lenp] = '\0';

    for(int i = 1; i < lenp; i++){

        flag = true;

        for(int j = 0; j < lenp; j++) if(ans[j] != ans[j%i]) flag = false;

        if(flag == true){

            anslen = i;
            break;

        }

    }

    if (flag == false) anslen = lenp;

    fp = fopen("p2_output.txt", "w");

    for(int i = 0; i < anslen; i++) fprintf(fp, "%c", ans[i]);

    fclose(fp);

    return 0;

}