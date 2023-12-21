#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        // Check if n is divisible by 3
        if (n % 3 == 0) {
            printf("Second\n");
        }
        else {
            
            printf("First\n");

        }
    }

    return 0;
}
