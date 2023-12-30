#ifndef __Card__
#define __Card__

#ifndef __DeckOfCards__
#define __DeckOfCards__

static char faceNames[13][6] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };
static char suitNames[4][9] = { "Clubs", "Diamonds", "Hearts", "Spades" };

typedef struct __Card {
    int face;
    int suit;
} Card;

typedef struct __DeckOfCards {
    Card* desk;
    int currentCard;
} DeckOfCards;

void construct(DeckOfCards* deck);

void shuffle(DeckOfCards* deck);

int compare(Card player1, Card player2);

#endif 
#endif 