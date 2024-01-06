#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){

    int n;
    scanf("%d", &n);
    while(n--){

        int a, b;
        scanf("%d %d", &a, &b);
        int* arr = (int*)calloc((a+b), sizeof(int));

        for(int i = 0; i < a; i++) scanf("%d", &arr[i]);

        int product = 1;
        for(int i = 0; i < a; i++) product *= arr[i];

        printf("Product: %d\n", product);

        if(product > 2023 || 2023 % product != 0){
                printf("NO\n");
                continue;
        }

        printf("YES\n");
        printf("%d ", 2023/product);

        for(int i = 0; i < b-1; i++){
            printf("1 ");
        }
        printf("\n");
    }
    return 0;
}