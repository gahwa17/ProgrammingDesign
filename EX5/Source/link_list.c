#include "myDS.h"
#include "basic.h"

// HEAD is point to FOODPAPA (id: 0)

// Please insert a new node(store Name & node_id)
// after the node which id is ID
// If it doesn't exit such ID, print "INVALID OPERATION"
void my_insert(struct node* HEAD, int ID, char *Name, int node_id){
	//Check if ID exist in list
	int flag = FALSE;
	struct node* ptr = HEAD;
	for( ; ptr != NULL ; ptr = ptr->next){
		if(ptr->id == ID){
			flag == TRUE;
			break;
		}
	}
	if(flag == FALSE)
		printf("INVALID OPERATION");
	//if ID exist,then create a new_node and insert after it
	else{
		struct node *new_node = malloc(sizeof(struct node));
		strcpy(new_node->name, Name);
		new_node->id = node_id;
		ptr->next = new_node;
	}
}

void my_delete(struct node* HEAD, char *Name){
	// Delete the node which store the Name.
	// If it doesn’t exit such Name, print “INVALID OPERATION”.

}
void my_swap(struct node *HEAD, char *Name1, char *Name2){
	// Swap the node which store Name1 and Name2
	// If either of the node doesn’t exit, print “INVALID OPERATION”
	// NOTICE: don't just swap the node's value
	// You need to break the link and recombine it
}
void my_print_id(struct node *HEAD, char *Name){
	// Print the id of the corresponding Name.
	// If Name doesn’t exit, print “INVALID OPERATION”
}
void my_print_name(struct node *HEAD, int ID){
	// Print the name of the corresponding ID
	// If ID doesn’t exit, print “INVALID OPERATION”
}

// Print out all the information in the linked list orderly
// in the format “ID NAME”. (start from HEAD)
void my_result(struct node* HEAD){
	for( ; HEAD != NULL ; HEAD = HEAD->next){
		printf("%d %s\n",HEAD->id,HEAD->name);
	}
}

