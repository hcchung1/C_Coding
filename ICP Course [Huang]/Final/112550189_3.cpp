#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include<ctype.h>
#include<math.h>
#include<string.h>

bool check(int n, const int* arr, int a, int b, int x) {
    int pa, pb;
    for (int i = 0; i < n; i++) {
        if (arr[i] == a) pa = i;
        if (arr[i] == b) pb = i;
    }
    if (pa - pb > x && pb + n - pa > x) return true;
    if (pb - pa > x && pa + n - pb > x) return true;
    return false;
}

void next_permutation(int n, int* arr, int a, int b, int x){

    int i = n - 1;
    int pa, pb;
    while (i > 0 && arr[i - 1] >= arr[i]) i--;
    if (i <= 0) {
        if (check(n, arr, a, b, x)) {
            for (int i = 0; i < n; i++) printf("%d", arr[i]);
            printf("\n");
        }
        return;
    }
    int j = n - 1;
    while (arr[j] <= arr[i - 1]) j--;
    int temp = arr[i - 1];
    arr[i - 1] = arr[j];
    arr[j] = temp;
    j = n - 1;
    while (i < j) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++; j--;
    }
    if (arr[0] != 1) {
        return;
    }
    // print next permutation
    if (check(n, arr, a, b, x)) {
        for (int i = 0; i < n; i++) printf("%d", arr[i]);
        printf("\n");
    }
    next_permutation(n, arr, a, b, x);
}

int main() {

    int n,a, b, x;
    int pa, pb;
    scanf("%d%d%d%d", &n, &a, &b, &x);
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) arr[i] = i+1;
    // find next permutation
    if (check(n, arr, a, b, x)) {
        for (int i = 0; i < n; i++) printf("%d", arr[i]);
        printf("\n");
    }
    next_permutation(n, arr, a, b, x);
}
