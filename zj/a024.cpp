#include<iostream>
using namespace std;
int main(){

    int year;
    cin >> year;

    if(year % 4 == 0 and year % 100 != 0)
    {
    
        cout << "閏年";

    }
    else if (year % 400 == 0)
    {

        cout << "閏年";

    }
    else
    {

        cout << "平年";

    }
    
}