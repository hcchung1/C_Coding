#include <stdio.h>

int arr[20000];

void swap(int *x, int *y) {

    int temp = *x;
    *x = *y;
    *y = temp;

}

int main(){
    int n, a=0;
    int len=0;
    
    // Read a series of non-zero numbers

    for(int i = 0; i < 20000; i++){

        scanf("%d", &arr[i]);
        if(arr[i] == 0){
            break;            
        }
        len++;

    }
    
    // Use the swap function to sort the array

    for(int i = 0; i < len; i++){

        for(int j = i; j < len; j++){

            if(arr[i] > arr[j]) 

                swap( &arr[i], &arr[j]);

        }
    }

    float medium;

    if (len%2 == 0){

        medium = (float)(arr[len/2-1] + arr[len/2])/2;

        printf("Medium: %.1f\n", medium);
    } 
    else{

        medium = (float)arr[len/2];
        printf("Medium: %d\n", medium);
    }

    return 0;
}