#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/* 
vowels — the letters a and e. They are represented by V
consonants — the letters b, c, and d. They are represented by C. 
Find CV and CVC in the string and separated them in '.'
example:
input: bacedbab
output: ba.ced.bab
*/


void solve(char* s, int m){

    char* ans = (char*)malloc(sizeof(char) *m+4);
    ans[m] = '\0', ans[m+1] = '\0', ans[m+2] = '\0', ans[m+3] = '\0';
    bool* pos = (bool*)calloc(m+4, sizeof(bool));
    int i = 0, j = 0;
    for(int i = 0; i < m; i++){

        if(s[i] == 'a' || s[i] == 'e') ans[i] = 'V';
        else ans[i] = 'C';
    }
    for(int i = 0; i < m; i++){

        if(ans[i+2] == 'C'){

            if(ans[i+3] == 'V') {
                pos[i+1] = true;
                i++;
                continue;
            }
            if(ans[i+3] == 'C') {
                pos[i+2] = true;
                i = i+2;
                continue;
            }

        }
        
    }

    for(int i = 0; i < m; i++){

        printf("%c", s[i]);
        if(pos[i]) printf(".");
    }
    printf("\n");

}

int main(){

    int n;
    scanf("%d", &n);
    while(n--){

        int m;
        scanf("%d", &m);
        char* s = (char*)malloc(sizeof(char) * m+1);
        scanf("%s", s);
        solve(s, m);



    }
}