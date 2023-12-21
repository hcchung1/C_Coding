#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>
int arr[500][500];
int Cx, Cy;
int howmany = 0;
int m;

int arrnumber(int Ci, int Cj){

    int output;

    if(Ci % 2 == 0){
            if(Cj % 2 == 0){

                return arr[Ci/2][Cj/2]/1000;

            }
            else {

                output = arr[Ci/2][Cj/2]/100 - (arr[Ci/2][Cj/2]/1000)*10;
                
                return output;

            } 

        }
    else {
        if(Cj % 2 == 0){

            output = arr[Ci/2][Cj/2]/10 - (arr[Ci/2][Cj/2]/100)*10;
            return output;

        }
        else{

            output = arr[Ci/2][Cj/2]/1 - (arr[Ci/2][Cj/2]/10)*10;
            return output;

        }


    }


}

int checknum(int Ci, int Cj){

    return (arrnumber(Ci, Cj) == 1)?(1):(-1);

}

int find(int Ci, int Cj){

    if(howmany != 0 && Cj == Cy) return 1;
    howmany++;

    for(int i = 0; i < m, i != Ci; i++){

        if(arrnumber(Ci, i) == 1) return(find(i, i+1));

    }

}

int main(){

    
    scanf("%d", &m);

    int num1, num2;
    
    if(m%2==0){

        for(int i = 0; i < m; i++){

            for(int j = 0; j < m/2; j++){

                scanf("%d %d", &num1, &num2);

                if(i%2 == 0){

                    arr[i/2][j] = num1*1000+num2*10;

                }
                else arr[i/2][j] += num1*100+num2*1;

            }

        }

    }
    else{

        for(int i = 0; i < m; i++){

            for(int j = 0; j < m/2+1; j++){

                if(j == m/2){
                    
                    scanf("%d", &num1);
                    (i%2 == 0)?(arr[i/2][j] = num1*1000):(arr[i/2][j] += num1*100);
                
                }
                else{

                    scanf("%d %d", &num1, &num2);
                    if(i%2 == 0){

                    arr[i/2][j] = num1*1000+num2*10;

                    }
                    else arr[i/2][j] += num1*100+num2*1;

                }

            }

        }


    }

    int times;
    scanf("%d", &times);

    for(int i = 0; i < times; i++){

        scanf("%d%d", &Cx, &Cy);
        //look up arr[Ci/2][Cj/2] 
        (checknum(Cx, Cy) == 1)?(printf("%d\n", checknum(Cx, Cy))):printf("%d\n", find(Cx, Cy));     

    }
    return 0;
}