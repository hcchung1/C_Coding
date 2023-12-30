#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>

int min(int x, int y){

    return (x>y)?(y):(x);

}

int main () {
    /* TODO */
    int x, y, ans;
    scanf("%d%d", &x, &y);
    ans = min(x, y);
    /* TODO (print the ans) */
    printf("The min of %d and %d is %d.\n", x, y, ans);
    system("pause");
    return 0;
}