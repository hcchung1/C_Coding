#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void count_distinct_strings(char* s, char** database) {
    // Find the number of different substrings of s, by deleting the first or the second character of s.
    int count = 0;
    char* t= (char*)malloc(strlen(s));
    
    
    
    // Print the number of distinct substrings.
    printf("%d\n", count);
}


int main() {

    int t;
    scanf("%d", &t);

    while(t--) {
        // Read the length of the string.
        int n;
        scanf("%d", &n);

        // Read the string.
        char* s = (char*)malloc((n + 1) * sizeof(char));
        char** database = (char**)malloc(strlen(s) * sizeof(char*));
        for (int i = 0; i < strlen(s); i++) {
            database[i] = (char*)malloc(strlen(s) * sizeof(char));
        }
        scanf("%s", s);
        s[n] = '\0';
        

        // Count the number of distinct strings.
        count_distinct_strings(s);
        free(s);
        free(database);
    }

    return 0;
}