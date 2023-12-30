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

    int K;


    

    for(int i = K-1; i >= 0; i++){

        if(s > (top[i]->speed)){

            tmp = top[i]->speed;
            top[i+1]->speed

        }
        
        else if(s == (top[i]->speed)){

            if(f > (top[i]->flexibility)){

                for(int j = K; j > i; j--){

                    top[j] = top[j-1];

                }
                top[i]->speed = s;
                top[i]->flexibility = f;
                top[i]->balance = b;
                break;

            }
            else if(f == (top[i]->flexibility)){

                if(b > (top[i]->balance)){

                    for(int j = K; j > i; j--){

                        top[j] = top[j-1];

                    }
                    top[i]->speed = s;
                    top[i]->flexibility = f;
                    top[i]->balance = b;
                    break;

                }
                else if(b == (top[i]->balance)){

                    for(int j = K; j > i+1; j--){

                        top[j] = top[j-1];

                    }
                    top[i+1]->speed = s;
                    top[i+1]->flexibility = f;
                    top[i+1]->balance = b;
                    break;

                }
            }
        }
    }

    
}
int main(){
    fallGuy* top = malloc(N*(sizeof(fallGuy)));
    int s, f, b;
    while(scanf("%d%d%d", &s, &f, &b) != EOF){
        rank(s, f, b, top);
    }
    return 0;
}