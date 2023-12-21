#include <stdio.h>
#include <stdlib.h>

int main(){

    int n;
    scanf("%d", &n);

    int* arr = (int*)malloc(n*sizeof(int));
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);

    for(int i = n; i >= 0; i--){
        int count = 0, small = 0;
        for(int j = 0; j < n; j++){
            if(arr[j] >= i) count++;
            if(arr[j] < i) small++;
        }
        if(count >= i && small <= n-i){
            printf("%d\n", i);
            break;
        }
    }

    system("pause");
    return 0;

}