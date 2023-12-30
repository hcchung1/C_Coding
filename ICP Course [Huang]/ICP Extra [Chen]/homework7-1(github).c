#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_DIGITS 400

// Function to parse the input string and extract the number and repetition count
void parse_input(char* input, char* number, int* count) {
    char* p = strchr(input, '@');
    *count = atoi(p + 1);
    strncpy(number, input, p - input);
    number[p - input] = '\0';
}

// Function to find the shortest repeated substring of a number
void find_shortest_substring(char* number, char* substring) {
    int len = strlen(number);
    int i, j, k;
    int min_len = len;
    for (i = 1; i <= len / 2; i++) {
        if (len % i == 0) {
            for (j = 0; j < i; j++) {
                for (k = 1; k < len / i; k++) {
                    if (number[j] != number[k * i + j]) {
                        break;
                    }
                }
                if (k < len / i) {
                    break;
                }
            }
            if (j == i) {
                min_len = i;
                break;
            }
        }
    }
    strncpy(substring, number, min_len);
    substring[min_len] = '\0';
}

// Function to add two numbers in the abbreviated format
void add_numbers(char* input1, char* input2, char* output) {
    char number1[MAX_DIGITS], number2[MAX_DIGITS], substring1[MAX_DIGITS], substring2[MAX_DIGITS], result[MAX_DIGITS];

    int count1, count2, count_result;

    parse_input(input1, number1, &count1);
    parse_input(input2, number2, &count2);

    find_shortest_substring(number1, substring1);
    find_shortest_substring(number2, substring2);
    
    long long int n1 = atoll(number1);
    long long int n2 = atoll(number2);
    long long int sum = n1 * count1 + n2 * count2;
    
    count_result = count1 + count2;
    
    sprintf(result, "%lld", sum);
    find_shortest_substring(result, output);
    sprintf(output + strlen(output), "@%d", count_result);
}

int main() {
    char input1[MAX_DIGITS], input2[MAX_DIGITS], output[MAX_DIGITS];
    scanf("%s %s", input1, input2);
    add_numbers(input1, input2, output);
    printf("%s\n", output);
    return 0;
}
