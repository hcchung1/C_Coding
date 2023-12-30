#ifndef STRUCT_H
#define STRUCT_H

extern char faceNames[13][6];
extern char suitNames[4][9];

typedef struct __Card {
    int face;
    int suit;
} Card;

typedef struct __DeckOfCards {
    Card* desk;
    int currentCard;
} DeckOfCards;

void construct(DeckOfCards *deck);
void shuffle(DeckOfCards *deck);
int compare(Card player1, Card player2);

#endif
