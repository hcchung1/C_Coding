#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>
int arr[26];

void get_line(char* str, FILE* fp) {

    while (1) {

        char c = getc(fp);

        *str = c;


        if (c == '\n') {

            *str = '\0';
            break;
        }
        else if (islower(c)) {
            arr[c - 'a']++;
            *str++;
        }
        else if (isupper(c)) {
            arr[c - 'A']++;
            *str++;
        }
        else {
            *str++;
            continue;
        }
    }
}


int main() {

    for (int i = 0; i < 26; i++) arr[i] = 0;

    FILE* fp = fopen("p2_input.txt", "r");
    FILE* fp2 = fopen("p2_output.txt", "w+");
    char* ciphertext = (char*)malloc(10000);
    char* plaintext = (char*)malloc(10000);

    get_line(ciphertext, fp);
    int max = 0;
    int maxch = 0;
    int shift;
    for (int i = 0; i < 26; i++) {
        if (arr[i] > max) {
            max = arr[i];
            maxch = i;
        }
    }
    shift = maxch + 'a' - 'e';
    shift *= -1;
    // printf("%d", shift);
    char text[100];
    int m = 0;
    int mmmm;

    for (int i = 0; i < strlen(ciphertext); i++) {

        if (isupper(ciphertext[i])) {

            if (ciphertext[i] + shift > 'Z') plaintext[i] = ciphertext[i] + shift - 26;
            else if (ciphertext[i] + shift < 'A') plaintext[i] = ciphertext[i] + shift + 26;
            else plaintext[i] = ciphertext[i] + shift;


        }
        else if (islower(ciphertext[i])) {

            if (ciphertext[i] + shift > 'z') plaintext[i] = ciphertext[i] + shift - 26;
            else if (ciphertext[i] + shift < 'a') plaintext[i] = ciphertext[i] + shift + 26;
            else plaintext[i] = ciphertext[i] + shift;
        }
        else {
            plaintext[i] = ciphertext[i];
        }
        fprintf(fp2, "%c", plaintext[i]);

    }




}