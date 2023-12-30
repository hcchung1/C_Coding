#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>

int main(){

    long long n;
    scanf("%lld", &n);

    long long grid[22][22] = {0};

    for(long long i = 0; i < n; i++){

        for(long long j = 0; j < n; j++){

            scanf("%lld", &grid[j][i]);

        }
    }

    long long expander;
    long long maximum = grid[0][0];
    long long temp = 0, posx = 0, posy = 0;

    scanf("%lld", &expander);
    //printf("%d", expander);

    for(long long i = 1; i <= expander; i++){

        maximum += grid[0][i] + grid[i][0];

    }
    //printf("maximum = %d\n", maximum);

    for(long long i = 0; i < n; i++){

        //printf("%d\n", i);

        for(long long j = 0; j < n; j++){

            //printf("%d\n", j);

            if(i == 0 && j == 0) continue;

            for(long long k = 0; k <= expander; k++){

                //printf("%d\n%d\n%d\n%d\n%d\n%d\n", j, i, grid[j+k][i], grid[j][i+k], grid[j-k][i], grid[j][i-k]);

                if(k == 0){

                    temp += grid[j][i];
                    continue;

                }

                if( j + k < n ) temp += grid[j+k][i];
                if( j - k >= 0 ) temp += grid[j-k][i];
                if( i + k < n ) temp += grid[j][i+k];
                if( i - k >= 0 ) temp += grid[j][i-k];
                //printf("%d %d\n", temp, k);

            }

            if(temp > maximum){

                //printf("maximum = %d\ntemp = %d\n", maximum, temp);

                maximum = temp;
                posx = j;
                posy = i;

                //printf("maximum = %d, posx = %d, posy = %d\n", maximum, posx, posy);

            }

            if((temp == maximum) && (j > posx)){

                maximum = temp;
                posx = j;
                posy = i;

            }
            if((temp == maximum) && (j == posx) && (i > posy)){

                maximum = temp;
                posx = j;
                posy = i;

            }

            temp = 0;

        }
    }

    printf("(%lld,%lld) %lld\n", posx, posy, maximum);

    return 0;

}