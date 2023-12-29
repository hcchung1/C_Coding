#include <stdio.h>
#include <math.h>

int main(){

    int n;
    scanf("%d", &n);

    while(n--){

        // input a, b
        int a, b;
        scanf("%d %d", &a, &b);

        //construct alpha, beta
        int* alpha = (int*)malloc(a*sizeof(int));
        int* beta = (int*)malloc(b*sizeof(int));
        for(int i=0; i<a; i++){
            scanf("%d", &alpha[i]);
        }
        for(int i=0; i<b; i++){
            scanf("%d", &beta[i]);
        }

        // calculate the array
        int* arr = (int*)malloc((a*b)*sizeof(int));
        for(int i=0; i<a; i++){
            for(int j=0; j<b; j++){
                arr[i*b+j] = alpha[i]*pow(2, beta[j]);
            }
        }

        int count = 0;

        for(int i = 0; i<a*b; i++){
            for(int j = i; j < a*b; j++){
                if(arr[i] > arr[j]){
                    count++;
                }
            }
        }
        printf("%d\n", count);
    }

}