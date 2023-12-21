#include <stdio.h>

int main(void) {

    // TODO: Do some initialize here

    int num[10] = {0};
    int len = 0;

    char c;
    while(scanf("%c", &c) != EOF) {

        int number = c - '0';
        num[number]++;
        len++;
        // TODO: You will get every digit of the number here

    }

    for(int i = 9; i >= 0; i--){

        for(int j = 0; j < num[i]; j++){

            printf("%d", i);

        }

    }
    // TODO: print out the answer
}