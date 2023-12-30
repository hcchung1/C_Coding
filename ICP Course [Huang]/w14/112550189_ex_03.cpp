#define _CRT_SECURE_NO_WARNINGS
#define SIZE 6
#include <stdio.h>
#include <stdlib.h>

void insertionSort(int* arr, int size);
void printArr(int* arr, int size);

int main() {
    int arr[SIZE], i;
    printf("Input number:\n");
    for (i = 0; i < SIZE; ++i) { scanf("%d", &arr[i]); }
    insertionSort(arr, SIZE);
    return 0;
}

void printArr(int* arr, int size) {
    int i;
    for (i = 0; i < size; ++i) { printf("%d ", *(arr + i)); }
    printf("\n");
}

void insertionSort(int* arr, int size) {
    int i, j;
    for (i = 1; i < size; i++) {
        /* TODO */
        int temp = *(arr + i);
        for (j = i - 1; j >= 0 && *(arr + j) > temp; j--) {
            *(arr + j + 1) = *(arr + j);
        }
        *(arr + j + 1) = temp;
        printf("Pass %d\n", i);
        printArr(arr, size);
    }
}
