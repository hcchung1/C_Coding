// Next Permutation
#include <stdio.h>
#include <stdlib.h>



int main(){

    int n;
    scanf("%d", &n);
    int* arr = (int*)malloc(n*sizeof(int));
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    // find next permutation
    int i = n-1;    
    while(i > 0 && arr[i-1] >= arr[i]) i--;
    if(i <= 0){
        for(int i = n-1; i >= 0; i--) printf("%d ", arr[i]);
        return 0;
    }
    int j = n-1;
    while(arr[j] <= arr[i-1]) j--;
    int temp = arr[i-1];
    arr[i-1] = arr[j];
    arr[j] = temp;
    j = n-1;
    while(i < j){
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
    // print next permutation
    for(int i = 0; i < n; i++) printf("%d ", arr[i]);

}

/* next permutation example: [1, 2, 3] -> [1, 3, 2] -> [2, 1, 3] -> [2, 3, 1] -> [3, 1, 2] -> [3, 2, 1] */