#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>

void swap(char *x, char *y) {
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void permute(char *a, int l, int r, int n, int *count){
    int i;
    if(l == r){

        char str_a[6], str_b[6];

        for (i = 0; i < 5; i++) {

            str_a[i] = a[i];
            str_b[i] = a[i + 5];

        }

        str_a[5] = '\0';
        str_b[5] = '\0';

        int num_a = atoi(str_a);
        int num_b = atoi(str_b);

        //printf("%d\n%d\n", num_a, num_b);

        /*puts(str_a);
        printf("\n");
        puts(str_b);
        printf("\n");*/

        if (num_b != 0 && num_a / num_b == n && num_a % num_b == 0) (*count)++;

    }
    else{

        for (i = l; i <= r; i++) {

            swap((a + l), (a + i));
            
            fputs(a, stdout);

            permute(a, l + 1, r, n, count);
            
            swap((a + l), (a + i));  // backtrack
        
        }
    }
    
}

int main(){
    
    int n; 
    int count = 0;

    char digits[] = "0123456789";
    
    scanf("%d", &n);

    permute(digits, 0, 9, n, &count);

    printf("%d\n", count);

    system("pause");
    return 0;
}