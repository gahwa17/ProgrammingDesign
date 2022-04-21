#include <stdio.h>
#include <stdlib.h>

struct node *add_to_list(struct node *list, int n);
struct node *search_list(struct node *list, int n);
struct node *delete_from_list(struct node *list, int n);

void add_to_list_void(struct node **list,int n);

//Declare a Node type
struct node{
    int value;
    struct node *next;  
};

int main(void){
    struct node *first = NULL;

    first = add_to_list(first, 10);
    add_to_list_void(&first, 20);

    printf("1->%d\n",first->value);
    printf("2->%d\n",(first->next)->value);

    struct node *search = search_list(first, 20);
    printf("Find %d\n",search -> value);

    first = delete_from_list(first, 20);
    printf("After del: 1->%d\n",first->value);
}

//Insert
struct node *add_to_list(struct node *list, int n){
    //1: Create a node.
    struct node *new_node;
    new_node = malloc(sizeof(struct node)); //new_node = malloc(sizeof(*new_node)); 
    
    if(new_node == NULL){
        printf("Error: malloc failed in add_to_list\n");
        exit(0);
    }

    //2: Assign value to new_node
    new_node -> value = n;

    //3: Insert this new_node into the beginning of list
    new_node -> next = list;

    //Return ptr of newly created node(Also current first node)
    return new_node;
}

//Search
struct node *search_list(struct node *list, int n){
    while(list != NULL && list -> value != n){
        list = list -> next;
    }
    return list;
}

//Delete
struct node *delete_from_list(struct node *list, int n){
    struct node *prev,*cur;

    for(cur = list,prev = NULL;
        cur != NULL && cur->value != n;
        prev = cur,cur = cur->next);

    //Can't find delete target 
    if(cur == NULL)
        return list;
    //target is in the first
    if(prev == NULL)
        list = list -> next; //list = NULL 
    else
        prev->next = cur->next;
    
    free(cur);

    return list;
}

//Insert (Double ptr version)
void add_to_list_void(struct node **list,int n){
    struct node *new_node;
    new_node = malloc(sizeof(struct node));
    if(new_node == NULL){
        printf("Error: malloc failed in add_to_list\n");
        exit(0);
    }
    //*list is alias of "first"
    new_node->value = n;
    new_node->next = *list;
    *list = new_node;
}

