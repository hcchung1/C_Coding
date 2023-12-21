#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>

int arr[20000];

int cmpfunc (const void * a, const void * b){

   return ( *(int*)a - *(int*)b );
   
}

int main(){
    int n, a=0;
    int len;

    for(int i = 0; i < 20000; i++){

        scanf("%d", &arr[i]);
        if(arr[i] == 0){
            break;
            len = i;
            
        }

    }
    
    // Read a series of non-zero numbers

    qsort(arr, len, sizeof(int), cmpfunc);
    
    // Use the swap function to sort the array

    printf("Results: ");

    for (int i=0; i<a; i++)

        printf("%d ", arr[i]);

    return 0;
}