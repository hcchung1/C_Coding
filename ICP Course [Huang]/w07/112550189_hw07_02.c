#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>

int max = 0, sum = 0;

int candy(int n, int t[], int place, int blockstojump, int timetojump){

    if(place == n) return max;

    for(int i = 0;i < n;i++){

        if( i == timetojump ){

            sum += t[place+blockstojump-1];
            place = place + blockstojump+1;

        }
        else{

            sum+=t[i];
            place = place + 2;

        }

    }
    if(sum > max){

        max = sum;

    }

}

int main(){

    int n;
    int t[10000]
    scanf("%d", &n);

    for(int i = 0; i < n; i++){

        scanf("%d", &t[i]);

    }

    printf("%d", candy(n, t, 0, 0, 0))

}