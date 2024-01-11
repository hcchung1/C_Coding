#include <stdio.h>

typedef struct Queue{
    int data[1000];
    int head;
    int tail;
}queue;

int main(){

    int n, m;
    scanf("%d %d", &n, &m);
    // Given a deck of cards with numbers from 1 to n arranged from top to bottom, a total of m draws will beconducted. In each draw, the top card is removed, and its number is outputted. Subsequently, the removed card is placed at the bottom of the deck.
    // For example, if n = 7 and m= 7, the output will be 1 3 5 7 4 2 6

    // use queue to store the cards
    queue q;
    q.head = 1;
    q.tail = 1;
    for(int i = 1; i <= n; i++){
        q.data[i] = i;
        q.tail++;
    }
    for(int i = 0; i < m; i++){
        printf("%d ", q.data[q.head]);
        q.head++;
        q.data[q.tail] = q.data[q.head];
        q.tail++;
        q.head++;
    }

    
    
    
}