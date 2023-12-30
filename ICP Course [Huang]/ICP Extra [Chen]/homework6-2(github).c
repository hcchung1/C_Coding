void delete(int p){
    if(head == NULL){
        printf("Invalid deletion\n");
        return;
    }
    if(p < 0){
        printf("Invalid deletion\n");
        return;
    }
    if(p == 0){
        Node* tmp = head;
        head = head->next;
        free(tmp);
        return;
    }
    Node* prev = head;
    for(int i = 0; i < p-1; i++){
        prev = prev->next;
        if(prev == NULL){
            printf("Invalid deletion\n");
            return;
        }
    }
    Node* tmp = prev->next;
    if(tmp == NULL){
        printf("Invalid deletion\n");
        return;
    }
    prev->next = tmp->next;
    free(tmp);
}
