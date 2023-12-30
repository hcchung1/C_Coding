#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int money;
    int ID;
    struct node* next;
} Node;

Node* head = NULL;
int lastPosition = -1;  // Record the position of the last operation

void queue(int ID, int money){

    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->ID = ID;
    newnode->money = money;

    if (head == NULL) {
        head = newnode;
        newnode->next = NULL;
    }
    else {
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newnode;
        newnode->next = NULL;
    }
    lastPosition++;
}

void deletenode(int p) {
    if (head == NULL || p < 0 || p > lastPosition) {
        printf("Invalid deletion\n");
        return;
    }

    if (p == 0) {
        Node* temp = head;
        head = head->next;
        free(temp);
    } else {
        Node* current = head;
        int index = 0;

        while (current != NULL && index < p - 1) {
            current = current->next;
            index++;
        }

        if (current == NULL || current->next == NULL) {
            printf("Invalid deletion\n");
            return;
        }

        Node* temp = current->next;
        current->next = current->next->next;
        free(temp);
    }

    lastPosition--;
}

void insert(int p, int ID, int money) {
    if (p < 0 || p > lastPosition + 1) {
        printf("Invalid insertion\n");
        return;
    }

    Node* newnode = (Node*)malloc(sizeof(Node));
    if (newnode == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newnode->ID = ID;
    newnode->money = money;

    if (p == 0) {
        newnode->next = head;
        head = newnode;
    } else {
        Node* current = head;
        int index = 0;

        while (current != NULL && index < p - 1) {
            current = current->next;
            index++;
        }

        if (current == NULL) {
            printf("Invalid insertion\n");
            free(newnode);
            return;
        }

        newnode->next = current->next;
        current->next = newnode;
    }

    lastPosition++;
}

void printList() {
    Node* node = head;
    while (node != NULL) {
        printf("ID money: %d %d\n", node->ID, node->money);
        node = node->next;
    }
    printf("\n");
}

void freeList() {
    Node* cur = head, *tmp;
    while (cur != NULL) {
        tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    head = NULL;
    lastPosition = -1;
}

int main() {
    int position, money, ID;
    int op, t;

    scanf("%d", &t);
    while (t--) {

        scanf("%d", &op);
        switch (op) {
        case 1:
            scanf("%d", &position);
            deletenode(position);
            // printf("headID: %d, headMoney: %d\n", head->ID, head->money);
            // printf("currentt: %d, ID: %d, Money: %d\n", currentt, current->ID, current->money);
            break;
        case 2:
            scanf("%d%d", &ID, &money);
            queue(ID, money);
            // printf("headID: %d, headMoney: %d\n", head->ID, head->money);
            // printf("currentt: %d, ID: %d, Money: %d\n", currentt, current->ID, current->money);
            break;
        case 3:
            scanf("%d%d%d", &ID, &money, &position);
            insert(position, ID, money);
            // printf("headID: %d, headMoney: %d\n", head->ID, head->money);
            // printf("currentt: %d, ID: %d, Money: %d\n", currentt, current->ID, current->money);
            break;
        default:
            printf("Wrong OP\n");
            break;
        }
    }

    printList();
    freeList();

    return 0;
}