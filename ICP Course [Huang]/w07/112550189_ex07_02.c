#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

int m;
char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };

void output(int n) {

    if (n >= 0) {

        printf("%c", arr[m - n - 1]);

        output(n - 1);

    }

    if (n == -1) {

        printf("\n");

    }

}

int main() {

    int n;

    scanf("%d", &n);

    m = n;

    output(n);

    //system("pause");
    return 0;

}