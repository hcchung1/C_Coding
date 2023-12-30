#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

int main () {
    char* s = (char*)malloc(50);
    char* m = (char*)malloc(50);
    register int index;

    
    // Use while loop to read input
    while(scanf("%s %s", s, m)!=EOF){
        // Get the length of m and s
        if(strlen(s) > strlen(m)) {

            printf("No\n");
            continue;

        }
        else if(strlen(s) == strlen(m)){

            if(strcmp(s, m) == 0) printf("Yes\n");
            else printf("No\n");

        }
        else{

            index = 0;
            for(register int i = 0; i < strlen(m); i++){

                if(s[index] == m[i]) index++;

            }
            if(index == strlen(s)) printf("Yes\n");
            else printf("No\n");

        }
        
        // Use a variable to record the index of m
        
        // Use loop to compare m and s
        
        // print the result
    }
}