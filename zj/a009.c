#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {

    char a[1000];
//    string a = "1JKJ'pz'{ol'{yhklthyr'vm'{ol'Jvu{yvs'Kh{h'Jvywvyh{pvu5";

    fgets(a, 1000, stdin);

    for(int i = 0; a[i]!='\n'; i++){

        a[i] = a[i] - 7;

    }
    printf("%s", a);

    

	system("pause");
	return 0;

}