# include <stdio.h>
# include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
} Node;

Node *head = NULL;

void insert(int p, int d){

    Node* newnode = NULL;
    newnode = (Node*)malloc(sizeof(Node));
    newnode->data = d;

    if (p == 0) {

        newnode->next = head;
        head = newnode;
    }
    else {

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

}

void printList(){
    Node* node = head;
    while(node != NULL){
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void freeList(){
    Node *cur = head, *tmp;
    while(cur != NULL){
        tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    head = NULL;
}

int main(){
    int position, data;
    char op;
    while(scanf(" %c", &op) != EOF){
        switch(op){
            case 'A':
                scanf("%d%d", &position, &data);
                insert(position, data);
                break;
            case 'B':
                printList();
                break;
            case 'C':
                freeList();
                break;
            default:
                printf("Wrong OP\n");
                break;
        }
    }
    return 0;
}