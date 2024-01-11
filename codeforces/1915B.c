#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

int main(){

    int m;
    scanf("%d", &m);
    bool flg = false;
    bool flagA = false, flagB = false, flagC = false;
    while(m--){
        for(int i = 0; i < 3; i++){
            char a, b, c;
            scanf("\n%c%c%c", &a, &b, &c);
            if (isalpha(a) && isalpha(b) && isalpha(c)) continue;
            else{

                if(a+b+c == 194) printf("C\n");
                if(a+b+c == 195) printf("B\n");
                if(a+b+c == 196) printf("A\n");
                    
            }
        }
    }
}