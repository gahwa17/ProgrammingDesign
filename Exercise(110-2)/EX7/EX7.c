#include <stdio.h>
#include <stdlib.h>

void quicksort(int data[],int left,int right);

int main(void){
    int num;
    scanf("%d", &num);
    int *id = malloc(sizeof(int)*num);
    int *score = malloc(sizeof(int)*num);

    for(int i = 0; i < num ; i++){
        scanf("%d %d",&id[i], &score[i]);
    }
    for(int i = 0; i < num ; i++){
        printf("id:%d score:%d\n",id[i], score[i]);
    }
}

void quicksort(int data[],int left,int right){

}