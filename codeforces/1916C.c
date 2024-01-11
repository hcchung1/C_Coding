#include <stdio.h>
#include <math.h>

int main(){

    int n;
    scanf("%d", &n);
    while(n--){

        int m, a, b;
        a = 0, b = 0;
        scanf("%d", &m);
        if(m == 1){
            scanf("%d", &a);
            printf("%d\n", a);
            continue;
        }
        while(m--){

            switch(m%2){

                case 1:
                    scanf("%d", &a);
                    if(b == 0) printf("%d\n", a);
                    else {
                        printf("m: %d, a: %d, b: %d\n", m, a, b);
                        a = floor((float)(a+b)/2)*2;
                        printf("%d\n", a);
                    }
                    break;

                case 0:
                    scanf("%d", &b);
                    if(a == 0) printf("%d\n", b);
                    else {
                        printf("m: %d, a: %d, b: %d\n", m, a, b);
                        b = floor((float)(a+b)/2)*2;
                        printf("%d\n", b);
                    }
                    break;

                default:
                    break;


            }

        }


    }

}