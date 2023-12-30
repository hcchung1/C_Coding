#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>

/* int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
} */

void combinations(int n, int k, int m, int comb[], int place) {

    if (place == k) {

        for (int i = 0; i < k; i++) {

            printf("%d", comb[i]);

        }

        printf("\n");
        return;
    }

    for (int i = m; i <= n; i++) {

        comb[place] = i;

        combinations(n, k, i + 1, comb, place + 1);

    }
}

int main() {

    int n, k, comb[9];

    scanf("%d %d", &n, &k);

    /* qsort(comb, strlen(comb), sizeof(int), cmpfunc); */

    combinations(n, k, 1, comb, 0);

    return 0;
}