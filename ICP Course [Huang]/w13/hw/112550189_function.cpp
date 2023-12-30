#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "112550189_struct.h"


bool check_id(char* id) {

    for (int i = 0; i < 100; i++) {
        if (strcmp(id, cuslist[i].id) == 0) {
            cuslist_now = i;
            return true;
        }
    }
    return false;

}

bool loginidcheck(char* id) {

    if (!isupper(id[0])) return false;
    int checksum = 0;
    checksum += ((id[0] - 'A' + 10) / 10) * 1 + ((id[0] - 'A' + 10) % 10) * 9;
    for (int i = 1; i < 9; i++) checksum += (id[i] - '0') * (9 - i);
    checksum = 10 - (checksum % 10) - (id[9] - '0');

    if(checksum == 0) {
        
        for (int i = 0; i < 100; i++) {
            if (strcmp(id, cuslist[i].id) == 0) {
                cuslist_now = i;
                return true;
            }
        }
    }
    return false;


}

bool registeridcheck(char* id) {

    if(!isupper(id[0])) return false;
    int checksum = 0;
    checksum += ((id[0] - 'A' + 10) / 10) * 1 + ((id[0] - 'A' + 10) % 10) * 9;
    for (int i = 1; i < 9; i++) checksum += (id[i] - '0') * (9 - i);

    if ((10 - (checksum % 10)) == (id[9] - '0')) return true;
    else return false;


}

void login() {

    printf("\nPlease enter your ID number: ");
    char id[20];
    scanf("%s", id);
    if (loginidcheck(id)) {
        printf("Enter your password: ");
        char password[20];
        scanf("%s", password);
        
        for (int i = 0; i < 100; i++) if (strcmp(id, cuslist[i].id) == 0) cuslist_now = i;
        if (strcmp(password, cuslist[cuslist_now].password) == 0) {
            printf("Login!\n");
            afterlogin();
        }
        else {
            printf("Wrong password. Please try again.\n");
            afterregister();
        }
    }
    else {
        printf("Invalid ID number. Please try again.\n"); //check here
        afterregister();
    }
}

void register_() {

    printf("\nPlease enter your ID number: ");
    char id[20];
    scanf("%s", id);
    if (loginidcheck(id)) {
        printf("ID already exists\n");
        afterregister();
    }
    else {

        if (!registeridcheck(id)) {
            printf("Invalid ID number. Please try again.\n");
            afterregister();
        }
        else {
            printf("Enter your password: ");
            char password[20];
            scanf("%s", password);
            printf("Enter your name: ");
            char name[20];
            scanf("\n%[^\n]s", name);
            printf("\nRegistration successful!\n");
            strcpy(cuslist[cuslist_size].id, id);
            strcpy(cuslist[cuslist_size].password, password);
            strcpy(cuslist[cuslist_size].name, name);
            cuslist_size++;
            afterregister();

        }
    }
}

void afterregister() {

    printf("\n1. Login\n2. Registration\n3. End\n\nEnter your choice (1~3): ");
	int choice;
	scanf("%d", &choice);
    switch (choice) {
        case 1:
            login();
            break;
        case 2:
            register_();
            break;
        case 3:
            printf("\nThank you! Goodbye!\n");
            return;
        default:
            printf("Invalid choice\n");
            break;
        }

}

void afterlogin() {

    printf("\n1. Make Reservation \n2. Reservation Enquiry/Canceling \n3. Log Out \n\nEnter your choice (1~3): ");
    int choice;
    scanf("%d", &choice);
    switch (choice) {
    case 1:
        make_reservation();
        break;
    case 2:
        reservation_enquiry();
        break;
    case 3:
        afterregister();
        break;
    default:
        printf("Invalid choice\n");
        break;
    }

}

void make_reservation() {
    //choose branch
    printf("\nPlease choose the branch (1-12):\n 1. Taipei Xinyi  \n 2. Taipei Fuxing  \n 3. Taipei Tienmu  \n 4. Taipei Taipei 101  \n 5. Taipei Nanxi  \n 6. Taipei A4  \n 7. Taipei A13  \n 8. Taipei Xinsheng  \n 9. Taipei Banqiao \n10. Hsinchu \n11. Taichung \n12. Kaohsiung \n");
    int branch;
    printf("\nEnter your choice (1~12): ");
    scanf("%d", &branch);
    // choose date, hour, number of customers
    printf("\nThe current date is %d/%d/%d %d:%d\n", currentyear, currentmonth, currentdate, currenthour, currentminute);
    printf("Available days: \n");
    for (int i = 0; i < 7; i++) {

        printf("%d. %d/%d/%d\n", i + 1, datearray[i][0], datearray[i][1], datearray[i][2]);
	}

    printf("\nEnter your choice (0 to end): ");
    int date;
    scanf("%d", &date);
    if(!date) {
        afterlogin();
        return;
    }
    date--;

    if (date == 0 && datearray[0][2] == currentdate) printf("\nEnter hour (%d~23): ", currenthour + 1);
    else printf("\nEnter hour (0~23):");
    int hour;
    scanf("%d", &hour);

    printf("\nEnter the number of customers (1~30, 0 to end): ");
    int num;
    scanf("%d", &num);
    if (!num) {
        afterlogin();
        return;
    }

    printf("\n              Branch           Date    Hour     No of Customers\n");
    // printf("%20s%11d-%2d-%2d%8d%20d\n", branches[branch], datearray[date][0], datearray[date][1], datearray[date][2], hour, num);
    printf("%20s", branches[branch]);
    printf("%9d-", datearray[date][0]);
    if(datearray[date][1] < 10) printf("0%d-", datearray[date][1]);
	else printf("%2d-", datearray[date][1]);
    if(datearray[date][2] < 10) printf("0%d", datearray[date][2]);
    else printf("%2d", datearray[date][2]);
    printf("%8d%20d\n", hour, num);
    printf("Reservation successful!\n");

    for (int i = 0; i < 100; i++) {

        if (cuslist[cuslist_now].reservation_detail[i][0] == 0) {
            cuslist_m++;
            cuslist[cuslist_now].reservation_detail[i][0] = branch;
            cuslist[cuslist_now].reservation_detail[i][1] = date;
            cuslist[cuslist_now].reservation_detail[i][2] = hour;
            cuslist[cuslist_now].reservation_detail[i][3] = num;
            cuslist[cuslist_now].reservation_detail[i][4] = cuslist_m;
            
            // printf("Your reservation: \nBranch: %d\nDate: 2023/12/0%d\nHour: %d\nNumber of customers: %d\n", cuslist[cuslist_now].reservation_detail[i][0], cuslist[cuslist_now].reservation_detail[i][1], cuslist[cuslist_now].reservation_detail[i][2], cuslist[cuslist_now].reservation_detail[i][3]);
            break;
        }

    }
    afterlogin();
}

void reservation_enquiry() {

    printf("\n                 Branch           Date    Hour     No of Customers\n");
    int count = 0;
    int count2 = 1;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (cuslist[cuslist_now].reservation_detail[j][0] != 0 && cuslist[cuslist_now].reservation_detail[j][4] == i) {
                // char date[15];
                // sprintf(date, "%d-%d-%d", , datearray[cuslist[cuslist_now].reservation_detail[i][1]][1], datearray[cuslist[cuslist_now].reservation_detail[i][1]][2]);
                printf("%d. %20s%9d-", count + 1, branches[cuslist[cuslist_now].reservation_detail[j][0]], datearray[cuslist[cuslist_now].reservation_detail[j][1]][0]);
                if (datearray[cuslist[cuslist_now].reservation_detail[j][1]][1] < 10) printf("0%d-", datearray[cuslist[cuslist_now].reservation_detail[j][1]][1]);
                else printf("%2d-", datearray[cuslist[cuslist_now].reservation_detail[j][1]][1]);
                if (datearray[cuslist[cuslist_now].reservation_detail[j][1]][2] < 10) printf("0%d", datearray[cuslist[cuslist_now].reservation_detail[j][1]][2]);
                else printf("%2d", datearray[cuslist[cuslist_now].reservation_detail[j][1]][2]);
                printf("%8d%20d\n", cuslist[cuslist_now].reservation_detail[j][2], cuslist[cuslist_now].reservation_detail[j][3]);
                count++;
                break;
            }
            
        }
    }
    printf("\nChoose a reservation to cancel (0: keep all reservations): ");
    int choice;
    scanf("%d", &choice);
    if (choice == 0) afterlogin();
    else {
        
        for(int i = 0; i <100; i++) if(cuslist[cuslist_now].reservation_detail[i][4] > cuslist[cuslist_now].reservation_detail[choice - 1][4]) cuslist[cuslist_now].reservation_detail[i][4]--;
        for (int i = 0; i < 5; i++) cuslist[cuslist_now].reservation_detail[choice - 1][i] = 0;
        cuslist_m--;
        printf("\nReservation deleted!\n");
        afterlogin();
    }

}

void datearrayspan() {

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 10; j++) {

            cuslist[i].reservation_detail[j][0] = 0;
            cuslist[i].reservation_detail[j][1] = 0;
            cuslist[i].reservation_detail[j][2] = 0;
            cuslist[i].reservation_detail[j][3] = 0;

        }
    }

    // start span date array using ctime in time.h 
    //The available dates start from 7 days after the current date, and the available hours start from one hour after the current hour. For example, if the current hour is 8 PM, the available dates would be from today onwards for the next six days, with the available hour of the first day (current day) starting from 9 PM. If the current hour is 11 PM, the available dates would be from tomorrow onwards for the next seven days. 
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    currentdate = tm.tm_mday;
    currenthour = tm.tm_hour;
    currentminute = tm.tm_min;
    currentmonth = tm.tm_mon + 1;
    currentyear = tm.tm_year + 1900;
    currentday = tm.tm_wday;
    if(currenthour == 23){

        for(int i = 1; i <= 7; i++){

            switch (currentmonth) {

                case 1: case 3: case 5: case 7: case 8: case 10:

                    if (currentdate + i > 31) {
                        datearray[i-1][0] = currentyear;
                        datearray[i-1][1] = currentmonth + 1;
                        datearray[i-1][2] = currentdate + i - 31;
                    }
                    else {
                        datearray[i-1][0] = currentyear;
                        datearray[i-1][1] = currentmonth;
                        datearray[i-1][2] = currentdate + i;
                    }
                    break;

                case 2: case 4: case 6: case 9: case 11:

                    if (currentdate + i > 30) {

                        datearray[i-1][0] = currentyear;
                        datearray[i-1][1] = currentmonth + 1;
                        datearray[i-1][2] = currentdate + i - 30;
                    }
                    else {
                        datearray[i-1][0] = currentyear;
                        datearray[i-1][1] = currentmonth;
                        datearray[i-1][2] = currentdate + i;
                    }
                    break;

                case 12:

                    if (currentdate + i > 31) {

                        datearray[i-1][0] = currentyear + 1;
                        datearray[i-1][1] = 1;
                        datearray[i-1][2] = currentdate + i - 31;
                    }
                    else {
                        datearray[i-1][0] = currentyear;
                        datearray[i-1][1] = currentmonth;
                        datearray[i-1][2] = currentdate + i;
                    }
                    break;
                default:
                    printf("Invalid month\n");
                    break;

            }



        }



    }
    else{
        for(int i = 0; i < 7; i++){
        
            switch (currentmonth) {

                case 1: case 3: case 5: case 7: case 8: case 10:

                    if (currentdate + i > 31) {
                        datearray[i][0] = currentyear;
                        datearray[i][1] = currentmonth + 1;
                        datearray[i][2] = currentdate + i - 31;
                    }
                    else {
                        datearray[i][0] = currentyear;
                        datearray[i][1] = currentmonth;
                        datearray[i][2] = currentdate + i;
                    }
                    break;

                case 2: case 4: case 6: case 9: case 11:

                    if (currentdate + i > 30) {

                        datearray[i][0] = currentyear;
                        datearray[i][1] = currentmonth + 1;
                        datearray[i][2] = currentdate + i - 30;
                    }
                    else {
                        datearray[i][0] = currentyear;
                        datearray[i][1] = currentmonth;
                        datearray[i][2] = currentdate + i;
                    }
                    break;

                case 12:

                    if (currentdate + i > 31) {

                        datearray[i][0] = currentyear + 1;
                        datearray[i][1] = 1;
                        datearray[i][2] = currentdate + i - 31;
                    }
                    else {
                        datearray[i][0] = currentyear;
                        datearray[i][1] = currentmonth;
                        datearray[i][2] = currentdate + i;
                    }
                    break;
                default:
                    printf("Invalid month\n");
                    break;

            }
        }
    }
}