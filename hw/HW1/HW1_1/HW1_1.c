#include <stdio.h>

int main(void){
    int num;
    scanf("%d",&num);
    int fac = 2;
    while(num > 1){
        if(num % fac == 0){
            printf("%d ",fac);
            num /= fac;
        }
        else
            fac++;
    }
}