#include <stdio.h>
#include <stdlib.h>

int min_val, max_val, pos_val, neg_val, zero_val;

int min_product(int *a, int n) {
    // Find the minimum and maximum values in the array.
    min_val = a[0];
    max_val = a[0];
	pos_val = 0;
	neg_val = 0;
	zero_val = 0;
    for (int i = 0; i < n; i++) {
		if(a[i] > 0) pos_val++;
		else if(a[i] < 0) neg_val++;
		else zero_val++;
        if (a[i] < min_val) {
            min_val = a[i];
        }
        if (a[i] > max_val) {
            max_val = a[i];
        }
    }

	
    int operations = 0;
    

	if(neg_val % 2 == 0 && neg_val != 0 && zero_val == 0) operations = 1;
	else if(neg_val % 2 == 0 && neg_val != 0 && zero_val != 0) operations = 0;
	else if(neg_val % 2 == 1 && neg_val != 0) operations = 0;
	else if(neg_val == 0 && zero_val != 0) operations = 0;
	else if(neg_val == 0 && zero_val == 0) operations = 1;
	else operations = 0;  

    return operations;
}

void print_operations(int *a, int n, int operations) {
    
	if(!operations) return;
	else printf("1 0\n");
}

int main() {
    // Read the number of test cases.
    int t;
    scanf("%d", &t);

    // Loop over the test cases.
    for (int i = 0; i < t; i++) {
        // Read the length of the array.
        int n;
        scanf("%d", &n);
		
        // Read the array of integers.
        int *a = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[j]);
        }

        // Find the minimum number of operations required to make the product equal to 1.
        int operations = min_product(a, n);

        // Print the minimum number of operations.
        printf("%d\n", operations);

        // Print the sequence of operations.
        print_operations(a, n, operations);

        // Free the allocated memory.
        free(a);
    }

    return 0;
}