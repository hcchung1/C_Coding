#include <stdio.h>
#include <stdlib.h>
#define head_of_color 97
#define max 50

struct data
{
    int nation;
    char color;
    struct data *next;
}node;
typedef struct data* graph;

graph neighbor[max];

int map[30][30];

int visited[max];

graph search_last_node(graph head, int nationn)
{
    graph ptr = head;
    printf("%d \\%d/\t", ptr->nation, nationn);
    while(ptr->next!=NULL){
        if((nationn==ptr->nation) || (nationn == 0)){
            printf("NULL\n");
            return NULL;
        }
        else{
            printf("%d -> ", ptr->nation);
            ptr = ptr->next;
        }
    }
    //printf("%d \n", ptr->nation);
    printf("return\n");
    return ptr;
}

void initialize_value()
{
    for(int i=0;i<max;i++){
        visited[i] = 0;
        //printf("neighbor[%d]:%x\n", i, &neighbor[i]);
        neighbor[i] = (graph) malloc(sizeof(node));
        //printf("neighbor[%d]:%x\n", i, &neighbor[i]);
        neighbor[i]->nation = i;
        neighbor[i]->next = NULL;
    }
    /*
    for(int i=0;i<max;i++){
        printf("Neighbor array Index :%d\n", neighbor[i]->nation);
    }
    */
}

void build_list()
{
     for(int i=0;i<30;i++){
        for(int j=0;j<30;j++){
            if(map[i][j] == 0){
                continue;
            }

            //The right one

            if(j<29){
                // set up a node
                graph new_node = (graph)malloc(sizeof(node));
                new_node->nation = map[i][j+1];
                //Find position
                printf("%2d %2d j::", i, j);
                graph position = search_last_node(neighbor[map[i][j]], new_node->nation);
                //printf("aa;%x\n", &position);
                //Link to the end of the linked list
                if(position != NULL){
                    //printf("before: new_node'%x', position '%x'\t", &new_node, &position->next);
                    position->next = new_node;
                    //printf("after: new_node '%x', position '%x'\n", &new_node, &position->next);
                }
                else if(position == NULL){
                    free(new_node);
                }
            }


            //The below one

            if(i<29){
                // set up a node
                graph new_nodee = (graph)malloc(sizeof(node));
                new_nodee->nation = map[i+1][j];
                //Find position
                printf("%2d %2d i::", i, j);
                graph positionn = search_last_node(neighbor[map[i][j]], map[i+1][j]);
                //printf("aa;%x\n", &positionn);
                //Link to the end of the linked list
                if(positionn != NULL){
                    //printf("before: new_node'%x', position '%x'\t", &new_nodee, &positionn->next);
                    positionn->next = new_nodee;
                    //printf("after: new_node '%x', position '%x'\n", &new_nodee, &positionn->next);
                }
                else if(positionn == NULL){
                    free(new_nodee);
                }
            }

        }
     }
}

void print_neighbor()
{
    printf("<<Adjacency List>>\nHead\t Adjacency nodes\n");
    int i=1;
    graph ptr;
    while(neighbor[i]->next != NULL){
        printf("%d\t", neighbor[i]->nation);
        ptr = neighbor[i]->next;
        while(ptr->next != NULL){
            ptr = ptr->next;
            printf("--> %d", ptr->nation);
        }
        i++;
        printf("\n");
    }
}

int main()
{
    //Set the array and linked list started value
    initialize_value();

    FILE *fp = fopen("color900_1.txt", "r");
    for(int i=0;i<30;i++){
        for(int j=0; j<30; j++){
            fscanf(fp, "%d ", &map[i][j]);
        }
    }
    fclose(fp);

    for(int i=0;i<30;i++){
        for(int j=0; j<30; j++){
            printf("%d ", map[i][j]);//
        }
        printf("\n");
    }

    build_list();

    print_neighbor();

    return 0;
}
