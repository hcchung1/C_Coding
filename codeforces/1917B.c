#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void count_distinct_strings(char* s) {
    // Find the number of different substrings of s, by deleting the first or the second character of s.
    
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
        scanf("%s", s);
        s[n] = '\0';
        

        // Count the number of distinct strings.
        count_distinct_strings(s);
    }

    return 0;
}