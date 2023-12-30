#include <stdio.h>
#include <stdlib.h>

int* compare(const char *S, const char *T, int N) {
    int *cmp = (int*)malloc(N * sizeof(int));

    for (int i = 0; i < N; i++) {
        cmp[i] = (S[i] == T[i]) ? 1 : 0;
    }

    return cmp;
}

int main() {
    int N;

    while (1) {
        scanf("%d", &N);

        if (N == 0) break;

        char *S = (char*)malloc(N * sizeof(char));
        char *T = (char*)malloc(N * sizeof(char));
        int *cmp;

        scanf("%s %s", S, T);

        cmp = compare(S, T, N);

        for (int i = 0; i < N; i++) {
            printf("%d", cmp[i]);
        }
        printf("\n");

        free(T);
        free(S);
        free(cmp);
    }

    return 0;
}
