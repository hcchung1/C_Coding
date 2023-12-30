#define _CRT_SECURE_NO_WARNINGS
#define SIZE 6
#include <stdio.h>
#include <stdlib.h>

void selectionSort(int* arr, int size);
void printArr(int* arr, int size);

int main() {
    int arr[SIZE], i;
    printf("Input number:\n");
    for (i = 0; i < SIZE; ++i) { scanf("%d", &arr[i]); }
    selectionSort(arr, SIZE);
    return 0;
}

void printArr(int* arr, int size) {
    int i;
    for (i = 0; i < size; ++i) { printf("%d ", *(arr + i)); }
    printf("\n");
}

void selectionSort(int* arr, int size) {
    int i, j;
    for (i = 0; i < size - 1; i++) {
        /* TODO */
        int min = i;
        for (j = i + 1; j < size; j++) {
            if (*(arr + j) < *(arr + min)) { min = j; }
        }
        int temp = *(arr + i);
        *(arr + i) = *(arr + min);
        *(arr + min) = temp;
        printf("Pass %d\n", i + 1);
        printArr(arr, size);
    }
}
