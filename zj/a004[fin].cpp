#include<iostream>
#include<algorithm>
#include<functional>
#include<math.h>
#include<stdlib.h>

using namespace std;

int year;

int main(){

    while (cin >> year){

        if (year % 4 == 0 and year % 100 != 0){

            printf("閏年\n");

        }
        else if(year %400 == 0){

            printf("閏年\n");

        }
        else {

            printf("平年\n");

        }

    }

    return 0;
}
