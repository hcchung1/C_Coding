#define _CRT_SECURE_NO_WARNINGS
# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# define N 10000

typedef struct fallguy{
    int speed;
    int flexibility;
    int balance;
}fallGuy;

void rank(int s, int f, int b, fallGuy* top){

    int K, p = 0;

    for(int i = 0; i < N;i++){

        if((top[i].speed) < 0) {
            K = i;
            break;
        }

    }
    //printf("%d\n", K);

    for(int i = 0; i < K; i++){

        //printf("s = %d\nf = %d\nb = %d\nspeed = %d\nflex = %d\nbal = %d\n", s, f, b, top[i].speed, top[i].flexibility, top[i].balance);

        if(s > (top[i].speed)){

            for(int j = K; j > i; j--){

                top[j] = top[j-1];

            }

            top[i].speed = s;
            top[i].flexibility = f;
            top[i].balance = b;
            p = i;
            break;

        }
        
        else if(s == (top[i].speed)){

            if(f > (top[i].flexibility)){

                for(int j = K; j > i; j--){

                    top[j] = top[j-1];

                }
                top[i].speed = s;
                top[i].flexibility = f;
                top[i].balance = b;
                p = i;
                break;

            }
            else if(f == (top[i].flexibility)){

                if(b > (top[i].balance)){

                    for(int j = K; j > i; j--){

                        top[j] = top[j-1];

                    }
                    top[i].speed = s;
                    top[i].flexibility = f;
                    top[i].balance = b;
                    p = i;
                    break;

                }
                else if(b == (top[i].balance)){

                    if(s == top[i+1].speed && f == top[i+1].flexibility && b == top[i+1].balance) continue;

                    for(int j = K; j > i+1; j--){

                        top[j] = top[j-1];

                    }
                    top[i+1].speed = s;
                    top[i+1].flexibility = f;
                    top[i+1].balance = b;
                    p = i+1;
                    break;

                }
            }
        }
    }

    if(K == 0){

        top[0].speed = s;
        top[0].flexibility = f;
        top[0].balance = b;

    }

    printf("%d ",K-p);

    
}
int main(){

    fallGuy* top =(fallGuy*) malloc(N*(sizeof(fallGuy)));
    int s, f, b;
    while(scanf("%d%d%d", &s, &f, &b) != EOF){
        rank(s, f, b, top);
    }
    return 0;
    
}