#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>

int* compare(const char* S, const char* T, int N) {

    int* cmp = (int*)malloc(N * sizeof(int));

    for (int i = 0; i <= (N - 1) / 2; i++) {

        cmp[i] = (S[i] == T[i]) ? (1) : (0);
        cmp[N - 1 - i] = (S[N - 1 - i] == T[N - 1 - i]) ? (1) : (0);

    }

    return cmp;
}


int main() {

    int N;
    // char* S = NULL;
    // char* T = NULL;
    char* S = (char*) malloc(INT_MAX * sizeof(char));
    char* T = (char*) malloc(INT_MAX * sizeof(char));

    while (1 > 0) {

        scanf("%d", &N);

        if (N == 0) break;

        // S = (char*)realloc(S, N+1);
        // T = (char*)realloc(T, N+1);
        int* cmp;

        fgets(S)

        cmp = compare(S, T, N);

        for (int i = 0; i < N; i++) {

            putchar('0' + cmp[i]);

        }
        printf("\n");


        free(cmp);

    }
    free(S);
    free(T);
    return 0;
}