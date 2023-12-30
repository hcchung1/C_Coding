#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>

int main(){

    int m, n, p;
    scanf("%d %d %d", &m, &n, &p);

    int a[10][10], b[10][10], ans[10][10];

    for(int i = 0; i < m; i++){

        for(int j = 0; j < p; j++){

            ans[i][j] = 0;
        }
    }

    //printf("%d %d %d\n", m, n, p);

    for(int i = 0; i < m; i++){

        for(int j = 0; j < n; j++){

            scanf("%d", &a[i][j]);

        }

    }
    for(int i = 0; i < n; i++){

        for(int j = 0; j < p; j++){

            scanf("%d", &b[i][j]);

        }

    }
    for(int i = 0; i < m; i++){

        for(int j = 0; j < p; j++){

            for(int k = 0; k < n;k++){

                ans[i][j] = ans[i][j] +( a[i][k] * b[k][j] );

            }
            //printf("%d", ans[i][j]);

        }

    }

    for(int i = 0; i < m; i++){

        for(int j = 0; j < p; j++){

            printf("%d", ans[i][j]);
            (j != p-1)?(printf(" ")):printf("\n");
        }
        
    }

    system("pause");
    return 0;
}