#include <stdio.h>

void even(int n){
    if(n < 1)
        return;
    if(n % 2 == 0){
        even(n - 2);
        printf("%d ",n);
    }
}
void odd(int n){
    if(n < 1)
        return;
    if(n % 2 == 1){
        odd(n - 2);
        printf("%d ",n);
    }
}

int main(void){
    int n;
    scanf("%d",&n);
    if(n % 2 == 0){
        even(n);
        printf("\n");
        odd(n - 1);
    }
    else{
        even(n-1);
        printf("\n");
        odd(n);
    }
    
}