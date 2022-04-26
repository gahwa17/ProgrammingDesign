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
			flag = TRUE;
			break;
		}
	}
	if(flag == FALSE)
		printf("INVALID OPERATION\n");
	//if ID exist,then create a new_node and insert after it
	else{
		struct node *new_node = malloc(sizeof(struct node));
		strcpy(new_node->name, Name);
		new_node->id = node_id;

		//if there is already other node, then keep it as tmp
		if(ptr->next != NULL){
			struct node *tmp = ptr->next;
			ptr->next = new_node;
			new_node->next = tmp;
		}
		//if there is no node,then just insert it
		else{
			ptr->next = new_node;
		}
	}
}


// Delete the node which store the Name.
// If it doesn’t exit such Name, print “INVALID OPERATION”.
void my_delete(struct node* HEAD, char *Name){
	int flag = FALSE;
	struct node* ptr = HEAD;
	//Find target node's former node
	while(ptr->next != NULL){
		if(strcmp((ptr->next)->name, Name) != 0)
			ptr = ptr->next;
		else{
			flag = TRUE;
			break;
		}
	}

	if(flag == FALSE)
		printf("INVALID OPERATION\n");
	else{
		struct node* to_delete = ptr->next;
		printf("Former is :%d %s\n",ptr->id,ptr->name);
		printf("To delete is :%d %s\n",to_delete->id,to_delete->name);
		ptr->next = to_delete->next;
		free(to_delete);
	}

}

// Swap the node which store Name1 and Name2
// If either of the node doesn’t exit, print “INVALID OPERATION”
// NOTICE: don't just swap the node's value
// You need to break the link and recombine it
void my_swap(struct node *HEAD, char *Name1, char *Name2){

}

// Print the id of the corresponding Name.
// If Name doesn’t exit, print “INVALID OPERATION”
void my_print_id(struct node *HEAD, char *Name){
	for( ; HEAD != NULL ; HEAD = HEAD->next){
		if(strcmp(HEAD->name, Name) == 0){
			printf("%d\n",HEAD->id);
			break;
		}
	}
	printf("INVALID OPERATION\n");
}


// Print the name of the corresponding ID
// If ID doesn’t exit, print “INVALID OPERATION”
void my_print_name(struct node *HEAD, int ID){
	for( ; HEAD != NULL ; HEAD = HEAD->next){
	if(HEAD->id == ID){
		printf("%s\n",HEAD->name);
		break;
		}		
	}
	printf("INVALID OPERATION\n");
}

// Print out all the information in the linked list orderly
// in the format “ID NAME”. (start from HEAD)
void my_result(struct node* HEAD){
	for( ; HEAD != NULL ; HEAD = HEAD->next){
		printf("%d %s\n",HEAD->id,HEAD->name);
	}
}

