#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>

int main(){

    int m, input;
    int nodes[101] = {0};
    int uept = 0;

    scanf("%d", &m); //1 <= m <= 100, no need to long long int

    int now = 0;//Alike four color problem, give different number so as to distinguish different nodes

    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){

            scanf("%d", &input);

            //if(j >= i) continue;//The upper triangle of matrix doesn't need to read in

            if(input == 1){

                /* printf("Before, nodes is now ");
                for(int k = 0; k < m; k++) printf("%d ", nodes[k]);
                printf("\n"); */

                if(nodes[i] != 0){
                    if(nodes[j] != 0){

                        if(nodes[i] != nodes[j]) uept++;

                        for(int k = 0; k < m, k != j; k++){

                            if(nodes[k] == nodes[j]) nodes[k] = nodes[i];

                        }
                        nodes[j] = nodes[i];
                    }

                    else nodes[j] = nodes[i];// if nodes[i] is not 0, but nodes[j] is. Make j the same as i
                    
                    continue;
                }

                if(nodes[j] != 0){
                    if(nodes[i] != 0){

                        if(nodes[i] != nodes[j]) uept++;

                        for(int k = 0; k < m, k != j; k++){

                            if(nodes[k] == nodes[j]) nodes[k] = nodes[i];

                        }
                        nodes[j] = nodes[i];
                    }

                    else nodes[i] = nodes[j];// if nodes[i] is not 0, but nodes[j] is. Make j the same as i
                    
                    continue;
                }

                if(nodes[i] == 0 && nodes[j] == 0){

                    now++;

                    nodes[i] = now;
                    nodes[j] = now;
                }

                /* printf("After change, nodes is now ");
                for(int k = 0; k < m; k++) printf("%d ", nodes[k]);
                printf("\n"); */

            }
        }
    }

    /* for(int i = 0; i < m; i++){

        if(nodes[i] == 0) now++;

    } */

    now -= uept;

    // printf("uept is %d\n", uept);

    printf("%d\n", now);

    return 0;
}