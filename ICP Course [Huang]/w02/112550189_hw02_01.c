#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main() {

	int a, b, c;

	scanf("%d %d %d", &a, &b, &c);

    int arr[3] = {a, b, c};

    //sort a, b, c into arr
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[j] > arr[i]) {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }

    //printf("%d %d %d", arr[0], arr[1], arr[2]);


    if(arr[0]+arr[1]-arr[2] > 0){

		printf("%d %d %d can form a triangle.\n", a, b, c);
	
	}
	
	else{

		printf("%d %d %d cannot form a triangle.\n", a, b, c);
        system("pause");
        return 0;

	}
	

	if ((arr[2] * arr[2]) - (arr[0] * arr[0]) - (arr[1] * arr[1]) == 0) {

		printf("%d %d %d can form a right triangle.\n", a, b, c);

	}
    else if((arr[0] * arr[0]) + (arr[1] * arr[1]) - (arr[2] * arr[2]) > 0){

        printf("%d %d %d can form a acute triangle.\n", a, b, c);

    }
    else{

        printf("%d %d %d can form a obtuse triangle.\n", a, b, c);

    }
    if(a == b && b == c){

        printf("%d %d %d can form a equilateral triangle.\n%d %d %d can form a isosceles triangle.\n", a, b, c, a, b, c);


    }
    else if(a == b || b == c || c == a){

        printf("%d %d %d can form a isosceles triangle.\n", a, b, c);

    }
    else{

        printf("%d %d %d can form a scalene triangle\n", a, b, c);

    }


	system("pause");
	return 0;


}