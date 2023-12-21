# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

void read_input(long int arr[], int len){

    long int sum = 0, min = INT_MAX, max = INT_MIN;
    double avg = 0;

    max = arr[0];
    min = arr[0];

    for(int i = 0; i < len; i++){

        if(arr[i] > max) max = arr[i];
        if(arr[i] < min) min = arr[i];
        sum += arr[i];

    }

    avg = 1.0 * sum / len;

    if(len == 0){

        len = 0;
        max = 0;
        min = 0;
        avg = 0;
    }    

    printf("number of integers: %d\n", len);
    printf("max: %ld\n", max);
    printf("min: %ld\n", min);
    printf("avg: %.2lf", avg);
}

int main(){

    long int arr[10000];
    int len = 0;

    while(len >= 0){

        scanf("%ld", &arr[len]);

        if(arr[len] == 0){

            break;

        }
        if(arr[len] != 0){

            len++;

        }


    }

    
    read_input(arr, len);
    return 0;
}
// this is a comment line
/* this is another 
comment line */