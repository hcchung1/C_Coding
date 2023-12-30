#include<stdio.h>
#include<stdlib.h>

int main(){

    int a, b;
    scanf("%d%d", &a, &b);

    printf("%d\n", a+b);
    printf("%d\n", a-b);
    printf("%d\n", a*b);
    printf("%.2f\n", (float) a/b);
    printf("%d\n", a%b);
    system("pause");
    return 0;

}