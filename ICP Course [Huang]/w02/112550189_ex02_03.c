#include<stdio.h>
#include<stdlib.h>

int main(){

    int a, b, c;
    printf("ax^2 + bx + c\nPlease input the coefficients: a b c\n");
    scanf("%d %d %d", &a, &b, &c);
    if(b^2-4*a*c == 0){

        printf("'%dx^2+%dx+%d' has double roots", a, b, c);

    }
    else if(b^2-4*a*c > 0){

        printf("'%dx^2+%dx+%d' has two distinct roots", a, b, c);

    }
    else{

        printf("'%dx^2+%dx+%d' has no real root", a, b, c);
    }

    return 0;


}