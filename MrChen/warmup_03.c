#include <stdio.h>
# include <stdlib.h>

int times = 0;

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

void read_input(int nums[]);

int main()
{
    int nums[10000] = {0};
    
    
    for(int i = 0;;i++){

        scanf("%d", &nums[i]);
        if(nums[i] == 0) break;
        if(nums[i] != 0) times++;

    }

    read_input(nums);

    return 0;
}

void read_input(int nums[])
{
    // TODO implement your read_input

    int arr[times] = {0};
    int z = 0;

    printf("Non-unique numbers: ");
    for(int i = 0; i < times; i++){

        for(int j = i+1; j < times; j++){

            if(nums[i] == nums[j] && nums[i] != 0){

                arr[z] = nums[i];
                z++;

                for(int k = i; k < times; k++){

                    if(nums[k] == arr[z-1]){
                        
                        nums[k] = 0;
                    
                    }

                }
            }

        }
    }

    int temp;

     for (int i = 0; i < z; i++) {

        for (int j = 0; j < i; j++) {

            if (arr[i] < arr[j]) {

                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;

            }
        }
    }

    for (int i = 0; i < z; i++) {
        printf("%d ", arr[i]);
    }

    // TODO print your result here
}