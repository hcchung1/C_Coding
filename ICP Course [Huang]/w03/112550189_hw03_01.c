#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main(){

    int times, trans, z=0;
    int place = 0;
    scanf("%d", &times);
    while(scanf("%d", &trans)){

        if (place == 0){

            if(trans == 10){

                place = 3;
                //printf("3\n");
                

            }
            else if(trans == 60 || trans == 43){

                place = 1;
                

            }
            else if(trans == 34 || trans == 16){

                place = 5;
                

            }
            else{

                place = 0;
                
            }

        }
        else if(place == 1){

            (trans == 15)?(place = 6):(place = 2);

        }
        else if(place == 2){

            if (trans == 23 || trans == 99){

                place = 7;

            }
            else place = 0;

        }
        else if(place == 3){

            place = 2;
            //printf("2\n");

        }
        else if(place == 4){

            place = 7;

        }
        else if(place == 5){

            (trans == 92)?(place = 6):(place = 4);

        } 
        else if(place == 6){

            (trans == 40 || trans == 56 || trans == 62)?(place = 4):(place = 5);

        }
        else if(place == 7){

            place = 7;

        }

        z++;
        if (z == times) break;


    }

    switch(place){

        case 0:

            printf("You are in Start.\n");
        
        case 1:

            printf("You are in S1.\n");
        
        case 2:

            printf("You are in S2.\n");
        
        case 3:

            printf("You are in S3.\n");

        case 4:

            printf("You are in S4.\n");

        case 5:

            printf("You are in S5.\n");

        case 6:

            printf("You are in S6.\n");

        case 7:

            printf("You are in Final.\n");


    }

    system("pause");
    return 0;


}