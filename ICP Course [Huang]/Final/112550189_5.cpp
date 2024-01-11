#include<stdio.h>
#include "112550189_pb05.h"

void fibonacci(int n) {

	printf("%d", fib(n));

}
int fib(int n) {

	if (n == 0) return 0;
	if (n == 1) return 1;
	return fib(n - 1) + fib(n - 2);
}