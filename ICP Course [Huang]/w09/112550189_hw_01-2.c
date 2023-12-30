#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>
#include<limits.h>

int* cmp;
int N;
char* S;
char* T;

int* compare(const char* S, const char* T, int N) {

    for (int i = 0; i <= (N - 1) / 2; i++) {

        cmp[i] = (S[i] == T[i]) ? (1) : (0);
        cmp[N - 1 - i] = (S[N - 1 - i] == T[N - 1 - i]) ? (1) : (0);

    }

    return cmp;
}


int main() {

    S = NULL;
    T = NULL;

    while (1) {

        scanf("%d", &N);
        getchar();

        if (N == 0) break;

        S = (char*)realloc(S, N+1);
        fgets(S, INT_MAX, stdin);

        T = (char*)realloc(T, N+1);
        fgets(T, INT_MAX, stdin);

        cmp = (int*)realloc(cmp, N * sizeof(int));

        cmp = compare(S, T, N);

        for (int i = 0; i < N; i++) {

            putchar('0' + cmp[i]);

        }
        printf("\n");


        free(cmp);

    }
}