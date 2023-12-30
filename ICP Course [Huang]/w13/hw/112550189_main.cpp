#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "112550189_struct.h"

int main() {

    printf("Welcome to the Din Tai Fung Reservation System!\n");
    int choice;
    datearrayspan();
    printf("\n1. Login\n2. Registration\n3. End\n\nEnter your choice (1~3): ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            login();
            break;
        case 2:
            register_();
            break;
        case 3:
            printf("Thank you! Goodbye!\n");
            return 0;
        default:
            printf("Invalid choice\n");
            afterregister();
            break;
    }
    
}