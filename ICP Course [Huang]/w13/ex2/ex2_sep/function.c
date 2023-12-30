#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "struct.h"

void construct(DeckOfCards* deck) {
    deck->currentCard = 0;
    deck->desk = (Card*)malloc(sizeof(Card) * 52);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            deck->desk[i * 13 + j].suit = i;
            deck->desk[i * 13 + j].face = j;
            deck->currentCard++;
        }
    }
}

void shuffle(DeckOfCards* deck) {
    srand(time(NULL));
    for (int i = 0; i < 52; i++) {
        int j = rand() % 52;
        Card temp = deck->desk[i];
        deck->desk[i] = deck->desk[j];
        deck->desk[j] = temp;
    }
}

int compare(Card player1, Card player2) {
    if (player1.face > player2.face) {
        return 1;
    }
    else if (player1.face < player2.face) {
        return 0;
    }
    else {
        if (player1.suit > player2.suit) {
            return 1;
        }
        else {
            return 0;
        }
    }
}