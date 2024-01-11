#include <stdio.h>

int main(){

    int n;
    scanf("%d", &n);
    while(n--){

        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);

        if(a == b) printf("%d\n", c);
        else if(a == c) printf("%d\n", b);
        else printf("%d\n", a);

    }
}