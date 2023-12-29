#include <stdio.h>
#include <math.h>

long long int pow_(long long int a, long long int b){
    long long int result = 1;
    while(b--) result *= a;
    return result;
}

int main(){

    long long int n;
    scanf("%lld", &n);

    while(n--){
        // input a, b
        long long int a, b;
        scanf("%lld %lld", &a, &b);

        //construct alpha, beta
        long long int* alpha = (long long int*)malloc(a*sizeof(long long int));
        long long int* beta = (long long int*)malloc(b*sizeof(long long int));
        for(long long int i=0; i<a; i++){
            scanf("%lld", &alpha[i]);
        }
        for(long long int i=0; i<b; i++){
            scanf("%lld", &beta[i]);
        }

        // calculate the array
        long long int* arr = (long long int*)malloc((a*b)*sizeof(long long int));
        for(long long int i=0; i<a; i++){
            for(long long int j=0; j<b; j++){
                arr[i*b+j] = alpha[i]*pow_(2, beta[j]);
            }
        }

        long long int count = 0;

        for(long long int i = 0; i<a*b; i++){
            for(long long int j = i; j < a*b; j++){
                if(arr[i] > arr[j]){
                    count++;
                }
            }
        }
        printf("%lld\n", count%998244353);
        free(alpha);
        free(beta);
        free(arr);
    }

}