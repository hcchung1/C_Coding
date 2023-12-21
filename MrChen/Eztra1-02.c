#include <stdio.h>
#include <limits.h>
#define N 20

int A[N][N];

int POINT(int max , int a, int b, int m, int n){
    for (int i=a-m; i<=a+m && i<n ; i++){
        if(i<0)
            continue;
        max+=A[i][b];
    }

    for (int i=b-m; i<=b+m&&i<n ; i++){
        if(i<0)
            continue;
        max+=A[a][i];
    }

    max-=A[a][b];
    
    return max;
}

int main()
{
    int n, m, Coordinate_point[2];
    scanf("%d",&n);
    for(int i=0; i<n ; i++){
        for(int j=0; j<n ; j++){
            scanf("%d",&A[i][j]);
        }
    }
    scanf ("%d",&m);
    int max=INT_MIN, a, b, point, temp;  // A[a][b]
    for (a=0; a<n; a++){
        for (b=0; b<n; b++){
            temp=max;
            point= POINT(0, a, b, m, n);
            //printf("%d %d\n",temp,point);
            if (point>=temp){
                max=point;
                Coordinate_point[0]=a;
                Coordinate_point[1]=b;
            }
            //printf("%d\n\n",max);
        }
    }
    printf("(%d,%d) %d\n", Coordinate_point[0], Coordinate_point[1], max);
    
    return 0;
}