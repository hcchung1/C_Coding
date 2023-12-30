#include <iostream>
using namespace std;

int main( ){

	int n, p;
	while(cin >> n){

		for(int i = 1; i <= n; i++){

			for(int k = 0;  k < (n-i); k++){
				cout << "_";
			}
			for(int k = 0;  k < i; k++){
				cout << "+";
			}
			cout <<'\n';
		}
	}
}