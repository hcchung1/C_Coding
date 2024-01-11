#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>

long long int smallerone(long long int N) {

	int z = 0;


	/*for (long long int i = 2; i < N; i++) {

		if (N % i == 0) return smallerone(N - 1);
		else continue;

	}*/

	for (long long int i = N; i > 2; i--) {

		for (long long int j = 2; j < i; j++) {

			if (i % j == 0) {
			
				z++;
				//return -10;
				break;

			}

		}
		
		if (z == 0) return i;
		z = 0;


	}

}

long long int biggerone(long long int N) {

	int k = 0;


	for (long long int i = N; ; i++) {

		for (long long int j = 2; j < i; j++) {

			if (i % j == 0) {
			
				k++;
				//return -20;
				break;
			}
			

		}
		if (k == 0) return i;
		k = 0;

	}

}

int main() {

	long long int N;

	scanf("%lld", &N);

	if ((N - smallerone(N)) == (biggerone(N) - N)) {
	
		printf("%lld\n", smallerone(N));
	
	}
	else if ((N - smallerone(N)) > (biggerone(N) - N)) printf("%lld\n", biggerone(N));
	else if ((N - smallerone(N)) < (biggerone(N) - N)) printf("%lld\n", smallerone(N));

	//printf("%lld\n%lld\n", smallerone(N), biggerone(N));

	

	return 0;
}