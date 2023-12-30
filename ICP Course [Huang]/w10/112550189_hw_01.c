#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>

char** A;
char** B;
int m, n;

void print(){

    printf("A:\n");

    for(int i = 0; i < m; i++){

        if(A[i] != NULL) fputs(A[i], stdout), printf("\n");
        else printf("(null)\n");

    }

    printf("B:\n");
    for(int i = 0; i < n; i++){

        if(B[i] != NULL) fputs(B[i], stdout), printf("\n");
        else printf("(null)\n");

    }
    return;

}

int main(){    

    scanf("%d%d", &m, &n);
    A = (char**)malloc(m*sizeof(char*));
    B = (char**)malloc(n*sizeof(char*));

    for(int i = 0; i < m; i++) A[i] = NULL;
    for(int i = 0; i < n; i++) B[i] = NULL;

    int p, x, y, s;
    while(1){

        scanf("%d", &p);

        if(p == 3) {
            print();
            break;
        }

        else if(p == 0){

            scanf("%d%d%d", &x, &y, &s);

            if(x == 0){

                if(y >= m) print();

                else if(A[y] == NULL){

                    A[y] = (char*)malloc(s*sizeof(char));
                    getchar();
                    fgets(A[y], s+1, stdin);
                    print();
                    continue;
                }

                else print();
            }
            else if(x == 1){

                if(y >= m) print();

                else if(B[y] == NULL){

                    B[y] = (char*)malloc(s);
                    getchar();
                    fgets(B[y], s+1, stdin);
                    print();

                }
                else print();

            }
            else print();
        }
        else if(p == 1){

            scanf("%d%d", &x, &y);
            if(x == 0){

                if(y >= m) print();
                else if(A[y] == NULL) print();
                else{
                    A[y] = NULL;
                    print();
                }
            }
            else if(x == 1){

                if(y >= n) print();
                else if(B[y] == NULL) print();
                else{
                    B[y] = NULL;
                    print();
                }
            }
            else print();

        }
        else{

            scanf("%d%d", &x, &y);

            if(x >= m || y >= n) print();
                
            else if(A[x] == NULL && B[y] == NULL) print();

            else if(A[x] == NULL && B[y] != NULL){

                A[x] = B[y];
                B[y] = NULL;
                print();
                // printtxt();

            }
            else if(A[x] != NULL && B[y] == NULL){

                B[y] = A[x];
                A[x] = NULL;
                print();
                // printtxt();

            }
            else{

                char* temp = NULL;
                temp = A[x];
                A[x] = B[y];
                B[y] = temp;
                print();
                // printtxt();

            }

        }

    }

    return 0;

}