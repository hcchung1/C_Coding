#include<iostream>
using namespace std;

int main(){

    int n, b, T;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> b >> T;
        for(int k = 0; k < T; k++){
            for(int t = 1; t <= b; t++){
                for(int a = 1; a <= t; a++){
                    cout << t;
                }
                cout << '\n';
            }
            for(int p = b-1; p >= 1; p--){
                for(int c = 1; c <= p; c++){
                    cout << p;
                }
                cout << '\n';
            }
            cout << '\n';
        }
        cout << '\n';
    }
}