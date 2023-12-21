#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* head = NULL;
int lastPosition = -1;  // Record the position of the last operation
Node* last = NULL;

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
        last = current;
        current->next = current->next->next;
        free(temp);
    }

    lastPosition--;
}

void insert(int p, int d) {
    if (p < 0 || p > lastPosition + 1) {
        printf("Invalid insertion\n");
        return;
    }

    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data = d;

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
        printf("%d ", node->data);
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
    int position, data;
    char op;

    while (scanf(" %c", &op) != EOF) {
        switch (op) {
            case 'A':
                scanf("%d%d", &position, &data);
                insert(position, data);
                break;
            case 'B':
                scanf("%d", &position);
                deletenode(position);
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
