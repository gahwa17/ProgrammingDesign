#include <stdio.h>
#include <string.h>

//Bonus3:Bubble, Insertion, Selection sort

// #define DEBUG

void Bubble(int num[],int n);
void Insertion(int num[],int n);
void Selection(int num[],int n);
void swap(int *a,int *b);


int main (void){
    int size;
    scanf("%d",&size);

    int num[size];
    for(int i = 0 ; i < size ; i++){
        scanf("%d",&num[i]);
    }

    char sort[20];
    scanf("%s",sort);

    if(strcmp(sort, "BUBBLE") == 0)
        Bubble(num,size);

    if(strcmp(sort, "INSERTION") == 0)
        Insertion(num,size);

    if(strcmp(sort, "SELECTION") == 0)
        Selection(num,size);

    #ifdef DEBUG
        for(int i = 0 ; i < size ; i++)
            printf("%d ",num[i]);
    #endif
}

void Bubble(int num[],int n){
    for(int i = n-1 ; i > 0 ; i--){
        for(int j = 0; j < i ; j++){
            if((j + 1) == n)
                break;
            if(num[j] > num[j+1])
                swap(&num[j], &num[j+1]);
        }
        for(int i = 0 ; i < n ; i++)
            printf("%d ",num[i]);
        printf("\n");
    }
}

void Insertion(int num[],int n){
    for(int i = 1 ; i < n ; i++){
        for(int j = i ; j > 0 ; j--){    //smallest compare times
            if(num[j] < num[j-1])
                swap(&num[j], &num[j-1]);
        }
        for(int i = 0 ; i < n ; i++)
            printf("%d ",num[i]);
        printf("\n");
    }
}

void Selection(int num[],int n){
    for(int i = 0 ; i < n-1 ; i++){
        int *min = &num[i];
        for(int j = i ; j < n ; j++){
            if(*min > num[j])
                min = &num[j];
        }
        swap(&num[i],min);
        for(int i = 0 ; i < n ; i++)
            printf("%d ",num[i]);
        printf("\n");
    }    
}

void swap(int *a,int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}