#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdbool.h>
#include<ctype.h>

struct AoT_Player {
    int player_id;
    char name[10];
} player[] = {{2, "Mikasa"}, {4, "Armin"}, {1, "Eren"}, {5, "Levi"}, {3, "Christa"}};

int main(){

    struct AoT_Player temp;

    //bobblesort for player_id
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 4 - i; j++){
            if(player[j].player_id > player[j + 1].player_id){
                temp = player[j];
                player[j] = player[j + 1];
                player[j + 1] = temp;
            }
        }
    }
    //print all player
    for(int i = 0; i < 5; i++){
        printf("{%d, %s}\n", player[i].player_id, player[i].name);
    }

}