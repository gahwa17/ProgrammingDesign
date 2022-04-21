//EX10 : 實作stack

#include <stdio.h>

void push();
void pop();
void display();

int main(void){
    int size , choice;
    int top = -1;
    int isExit = 0;
    printf("Enter the size of the stack : ");
    scanf("%d", &size);
    int stack[size];

    while(isExit == 0){
        printf("1.Push 2.Pop 3.Display 4.Exit: ");
        scanf("%d", &choice);
        switch(choice){
            case 1 :
                push(stack,&top,size);
                break;
            case 2 :
                pop(stack,&top);
                break;
            case 3 :
                display(stack,&top);
                break;
            case 4 :
                isExit = 1;
                break;
            default :
                printf("Invalid Choice\n");
                break;
        }
    }
}

void display(int stack[],int *top){
    // printf("Display Top: %d\n", *top);
    if((*top) == -1){
        printf("Stack underflow\nStack is empty\n");
        return;
    }
    for (int i = *top; i > -1 ; i--){
        printf("-> %d\n", stack[i]);
    }
}

void push(int stack[],int *top,int size){
    if((*top) == size-1){
        printf("Stack overflow\n");
        return;
    }
    else{
        int data;
        printf("Enter the item to be pushed : ");
        scanf("%d", &data);
        stack[(*top) + 1] = data;
        // printf("Push Top: %d\n", (*top) + 1 );
        (*top)++;
        display(stack,top);
    }
    
}

void pop(int stack[],int *top){
    if((*top) == -1){
        printf("Stack underflow\nStack is empty\n");
        return;
    }
    else{
        printf("Element %d has been popped from the stack\n", stack[--(*top)]);
        display(stack,top);
    }
    
    // printf("Pop Top: %d\n", *top);
}