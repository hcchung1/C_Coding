#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>

#define MSG_LEN 60

// Caesar cipher
void Caesar(char* msg, int k) { // Receive the message and the shift number
    int idx = 0; // Declare idx to store the index of the message
    while(idx < strlen(msg)) { // Use while loop to iterate the string, until the end of the string
        
        // Use pointer and idx to access the character of string
        if (msg[idx] <= 'Z' && msg[idx] >= 'A') { // If the character is uppercase
            msg[idx] = (int)(msg[idx] - 'A' + k) % 26 + 'A'; // Use the formula to shift the character, and wrap around if the character is out of range
        } 
        else if (msg[idx] >= 'a' && msg[idx] <= 'z') { // If the character is lowercase
            msg[idx] = (int)(msg[idx] - 'a' + k) % 26 + 'a'; // Use the formula to shift the character, and wrap around if the character is out of range
        }
        idx++; // Increment idx
    }
}

// Reverse the string
void reverse(char* msg) { // Receive the message
    register int i = 0;// Declare a temp variable and a pointer to the end of the string
    register int len = strlen(msg);
    //printf("len = %d\n", len);
    char temp;
    while (i < (len/2)) { // Use while loop to iterate the string, until the pointer is at the beginning of the string
        // Swap the character at the beginning and the end of the string
        temp = msg[i]; 
        //printf("temp = %c\n", temp);
        msg[i] = msg[len - 1 - i];
        msg[len - 1 - i] = temp;
        i++;
    }
}

int read_line(char str[], int n) {
    int ch, i = 0;
    while (1) { 
        ch = getchar();
        if (ch == '\n' || ch == EOF)
            break;
        if (i < n)
            str[i++] = ch;
    }
    str[i] = '\0';
    return i;
}

int main() {
    int n; // Declare n to store the number of test cases
    scanf("%d", &n); // Read the input of test cases
    getchar(); // Use getchar() to read the newline character, otherwise the newline character will be read in the next read_line()
    while (n > 0) { // Use while loop to iterate the test cases
        char msg[MSG_LEN+1]; // Declare msg to store the message, +1 for the null character
        int k; // Caeser cipher shift number
        read_line(msg, MSG_LEN); // Read the message
        scanf("%d", &k); // Read the shift number
        getchar(); // Use getchar() to read the newline character
        Caesar(msg, k);// Call the Caesar function
        //printf("complete caesar\n");
        reverse(msg);// Call the reverse function
        //printf("complete reverse\n");
        fputs(msg, stdout);
        putchar('\n');
        //printf("\ncomplete print\n");
        n--; 
    }
    return 0;
}