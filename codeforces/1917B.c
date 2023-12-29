#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/* void count_distinct_strings(char* s, char** database) {
    // Find the number of different substrings of s, by deleting the first or the second character of s.
    int count = 0;
    char* t= (char*)malloc(strlen(s));
    sprintf(t, "%s", s+1);
    bool flag = true;
    for(int i=0; i<strlen(s); i++){
        if(strcmp(t, database[i])==0){
            flag = false;
            break;
        }
    }
    if(flag){
        count++;
        strcpy(database[count], t);
    }
    count

    
    
    
    // Print the number of distinct substrings.

    printf("%d\n", count);
} */

int count_distinct_strings(char* s, char** database) {
    // Find the number of different substrings of s, by deleting the first or the second character of s.
    int count = 0;
    char* t = (char*)malloc(strlen(s));
    sprintf(t, "%s", s + 1);
    bool flag = true;
    for (int i = 0; i < strlen(s); i++) {
        if(database[i] == NULL) break;
        if (strcmp(t, database[i]) == 0) {
            flag = false;
            break;
        }
    }
    if (flag) {
        count++;
        strcpy(database[count], t);
    }
    count += count_distinct_strings(t, database); // Recursively count distinct strings for the modified string.
    
    // Print the number of distinct substrings.
    return count;
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
        char** database = (char**)malloc((n+1) * sizeof(char*));
        for (int i = 0; i < n; i++) database[i] = (char*)malloc((n+1) * sizeof(char));
        
        scanf("%s", s);
        s[n] = '\0';
        for(int i = 0; i < n; i++) database[0][i] = s[i]; 

        // Count the number of distinct strings.
        printf("%d", count_distinct_strings(s, database));
        free(s);
        free(database);
    }

    return 0;
}