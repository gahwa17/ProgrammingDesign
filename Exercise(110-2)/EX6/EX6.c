#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 100

struct node *add_to_end(struct node *start, char *name);
void print_list(struct node *start, int num);
void kill_node(struct node *start, int kill);
int count_node(struct node *start);

struct node{
    char name[MAX_NAME];
    struct node *next;
    struct node *prev;
};

int main(void){
    struct node *start = NULL;
    int num, kill;
    char name[MAX_NAME], *direction;
    memset(name, '\0', strlen(name)); //Init

    scanf("%d", &num);

    for(int i = 0 ; i < num; i++){
        scanf("%s", name);
        // printf("%d: %s\n",i, name);
        start = add_to_end(start, name);
    }

    scanf("%d %s", &kill, &direction);
    // print_list(start, num);

    kill_node(start, kill);
}

struct node *add_to_end(struct node *start, char *name){
    //Create new_node
    struct node *new_node = malloc(sizeof(struct node));
    strcpy(new_node->name, name);
    // strncpy(new_node->name, name, strlen(name)); Q: Why trash value???

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

void print_list(struct node *start, int num){
    struct node *ptr = start;
    for (int i = 0; i < num ; i++){
        printf("%s ",ptr->name);
        ptr = ptr->next;
    }
    ptr = start->prev;
    for (int i = 0; i < num ; i++){
        printf("%s ",ptr->name);
        ptr = ptr->prev;
    }
}

void kill_node(struct node *start, int kill){
    struct node *cur = start;
    struct node *to_kill;

    int left_node;

    while (left_node != 1){
        //Find kill target
        for (int i = 0; i < kill ; i++){
            cur = cur->next;
            to_kill = cur;
        }

        // printf("---Before kill---\n");
        // printf("to_kill node:%s\n", to_kill->name);

        //Modify pointer
        (to_kill->next)->prev = to_kill->prev;
        (to_kill->prev)->next = to_kill->next;
        cur = to_kill->next;

        //Kill node
        printf("%s KILLED\n", to_kill->name);
        free(to_kill);

        // printf("---After kill---\n");
        // printf("cur node:%s\n", cur->name);

        left_node = count_node(cur);
        // printf("left node: %d\n",left_node);
    }

    printf("%s SURVIVE\n", cur->name);
    
}

int count_node(struct node *start){
    int total = 0;
    struct node *ptr = start;

    // printf("---COUNT---\n");

    do{
        // printf("cur is %s\n",ptr->name);
        total++;
        ptr = ptr->next;
    }while(ptr != start);

    return total;
}