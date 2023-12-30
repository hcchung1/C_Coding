#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int main(){

    FILE * fp;

    fp = fopen ("file.txt", "w+");

    fprintf(fp, "6 6 6\n");

    for(long long int i = 0; i < 6; i++){

        for(int j = 0; j < 6; j++){

            fprintf(fp, "%d ", (i*6+j+1));

        }

        fprintf(fp, "\n");

    }

    for(long long int i = 0; i < 6; i++){

        for(int j = 0; j < 6; j++){

            fprintf(fp, "%d ", (i*6+j+37));

        }

        fprintf(fp, "\n");

    }    
   
    fclose(fp);
   
    return(0);

}