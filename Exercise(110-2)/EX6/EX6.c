#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 100

struct node *add_to_end(struct node *start, char *name);
void print_list(struct node *start, int num);
void kill_node(struct node *start, int kill, char direction[]);
int count_node(struct node *start);

struct node{
    char name[MAX_NAME];
    struct node *next;
    struct node *prev;
};

int main(void){
    struct node *start = NULL;
    int num, kill;
    char name[MAX_NAME];
    char direction[20];

    //初始化字元陣列
    memset(name, '\0', strlen(name));
    memset(direction, '\0', strlen(direction));

    scanf("%d", &num);
    //讀取人名，建立環
    for(int i = 0 ; i < num; i++){
        scanf("%s", name);
        start = add_to_end(start, name);
    }

    scanf("%d %s", &kill, direction);
    kill_node(start, kill, direction);
}

struct node *add_to_end(struct node *start, char *name){
    //Create new_node
    struct node *new_node = malloc(sizeof(struct node));
    strcpy(new_node->name, name);

    //If list is empty
    if(start == NULL){
        new_node->next = new_node;
        new_node->prev = new_node;
        start = new_node;
    }
    else{
        struct node *old_last = start->prev; //Find old_last node
        new_node->next = start; //new_node is going to be the lastes node, so its next will be start
        start->prev = new_node; //new_node is going to be the lastes node, so start's prev will be new_node

        new_node->prev = old_last;//Make new_node become the next of last node,so it's the newest last node
        old_last->next = new_node;
    }
    
    return start;
}

void kill_node(struct node *start, int kill, char direction[]){
    struct node *cur = start;
    int left_node = count_node(cur);
    
    while (left_node != 1){
        struct node *to_kill = NULL;
        //順時針
        if(strcmp(direction, "CLOCKWISE") == 0){
            //Find kill target
            for (int i = 0; i < kill ; i++){
                cur = cur->next;
            }
            to_kill = cur;

            //Modify pointer
            (to_kill->next)->prev = to_kill->prev;
            (to_kill->prev)->next = to_kill->next;
            cur = to_kill->next;

            //Kill node
            printf("%s KILLED\n", to_kill->name);
            free(to_kill);
        }
        //逆時針
        else{
            //Find kill target
            for (int i = 0; i < kill ; i++){
                cur = cur->prev;
            }
            to_kill = cur;

            //Modify pointer
            (to_kill->next)->prev = to_kill->prev;
            (to_kill->prev)->next = to_kill->next;
            cur = to_kill->prev;

            //Kill node
            printf("%s KILLED\n", to_kill->name);
            free(to_kill);
        }
        
        left_node = count_node(cur);
    }

    printf("%s SURVIVE\n", cur->name);
    
}

int count_node(struct node *start){
    int total = 0;
    struct node *ptr = start;
    do{
        total++;
        ptr = ptr->next;
    }while(ptr != start);

    return total;
}