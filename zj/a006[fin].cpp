#include<iostream>
#include<cmath>

using namespace std;

int a, b, c, answer, ans1, ans2;

int main(){

    cin >> a >> b >> c;
    if (b*b - 4*a*c < 0) printf("No real root\n");
    else if (b*b - 4*a*c == 0) {

        answer = (-b)/(2*a);
        printf("Two same roots x=%d\n", answer);

    }

    else {

        //cout << (sqrt(b*b - 4*a*c)) << '\n';

        ans1 = ((-b)+(sqrt(b*b - 4*a*c)))/(2*a);
        ans2 = ((-b)-(sqrt(b*b - 4*a*c)))/(2*a);
        printf("Two different roots x1=%d , x2=%d\n", ans1, ans2);


    }

    return 0;

}