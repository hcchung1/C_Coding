#include<iostream>
#include<algorithm>
#include<functional>
#include<math.h>
#include<stdlib.h>

using namespace std;

int main(){

    int linenum;
    int num1, num2, num3, num4, num5;
    cin >> linenum;
    int i = 0;
    while(i<linenum){

        cin>>num1>>num2>>num3>>num4;
        num5 = (num2*2 == num1+num3)?2*num3-num1:num3*num3/num1;
        cout << num1 << " " << num2 << " " << num3 << " " << num4 << " " << num5 << "\n";
        i = i+1;
    }

    return 0;
    
}