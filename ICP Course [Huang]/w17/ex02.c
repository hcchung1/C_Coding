#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* void get_line(char* s){
    getchar();
    char c;
    int i = 0;
    while(1){
        c = getchar();
        if(c == '\n' && i!=0) break;
        s[i] = c;
        i++;
    }
    s[i] = '\0';
} */

int main(){

    int n;
    scanf("%d", &n);
    char* s = (char*)malloc(sizeof(char) * 1000);
    scanf("%s", s);
    // get_line(s);
    char* ans = (char*)malloc(sizeof(char) * 1000); 
    int fxck = n*2-2;
    int now = 0;
    if(n == 1){
        printf("%s\n", s);
        return 0;
    }
    for(int i = 0; i < strlen(s); i+=fxck){
        ans[now] = s[i];
        now++;
    }
    
    
    for (int i = 1; i < n-1; i++){
        
        for(int j = i; j < strlen(s); j+=fxck){

            ans[now] = s[j];
            now++;
            if(j+fxck-i*2 < strlen(s)){
                
                ans[now] = s[j+fxck-i*2];
                now++;
            }
        }
    }
    for(int i = n-1; i < strlen(s); i+=fxck){
        ans[now] = s[i];
        now++;
    } 

    ans[now] = '\0';
    printf("%s\n", ans);
    
}