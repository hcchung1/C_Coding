#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

int main(){

    FILE * fp;
    int S, C;

    fp = fopen ("ex2_input.txt", "r");
    fscanf(fp, "%d%d", &S, &C);
    fclose(fp);
    int count;
    fp = fopen ("ex2_output.txt", "w+");

    switch(S){

        case 1:

            for(int i = 1; i <= C; i++){

                for(int j = 0; j < i; j++) fprintf(fp, "* ");
                if(i != C) fprintf(fp, "\n");

            }              
            break;
        case 2:

            for(int i = 1 ; i <= C; i++){

                for(int j = 0; j < (C-i); j++) fprintf(fp, " ");
                for(int j = 0; j < i; j++){

                    fprintf(fp, "*");
                    if(j != i-1) fprintf(fp, " ");

                }
                //for(int j = 0; j < C-i; j++) fprintf(fp, " ");
                if(i != C) fprintf(fp, "\n");                

            }

            /* for(int i = 1 ; i <= C; i++){

                for(int j = 0; j < (C-i); j++) printf(" ");

                for(int j = 0; j < i; j++){

                    printf("*");
                    if(j != i-1) printf(" ");

                }

                if(i != C) printf("\n");                

            } */
            
            break;

        case 3:

            count = C*2-1;
            for(int i = 1; i <= C; i++){

                for(int j = count-(i*2-1); j >= 1; j--) fprintf(fp, " ");
                for(int j = 1; j <= i; j++) fprintf(fp, "* ");
                if(i != C) fprintf(fp, "\n");

            }
            
            break;

        default:
            printf("Invalid input\n");
            break;


    }

    fclose(fp);
    return 0;

}