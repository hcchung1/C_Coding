#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

char** arr;
int now = 0;

void permute(char* stack, int n, int i){
    if(i == n){
        if(stack[0] == ')' || stack[n-1] == '(') return;
        for(int j = 0, count = 0; j < n; j++){
            if(stack[j] == '(') count++;
            else count--;
            if(count < 0) return;
        }
        for(int j = 0; j < now; j++){
            if(strcmp(arr[j], stack) == 0) return;
        }
        arr[now] = (char*)malloc(sizeof(char) * (n+1));
        strcpy(arr[now++], stack);
        printf("%s\n", stack);
        return;
    }

    for(int j = i; j < n; j++){
        char temp = stack[i];
        stack[i] = stack[j];
        stack[j] = temp;

        permute(stack, n, i+1);

        temp = stack[i];
        stack[i] = stack[j];
        stack[j] = temp;
    }
}

int main(){

    int n;
    scanf("%d", &n);

    arr = (char**)malloc(sizeof(char*) * INT_MAX);
    arr[0] = (char*)malloc(sizeof(char) * (n+1));

    //permute all the legal bracket combinations by using recursion
    

    char* stack = (char*)malloc(sizeof(char) * n * 2);
    for(int i = 0; i < n; i++){
        stack[i] = '(';
        stack[i+n] = ')';
    }
    stack[n*2] = '\0';

    permute(stack, n*2, 0);
    



}