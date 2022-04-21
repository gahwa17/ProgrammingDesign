#include <stdio.h>

#define INT_KIND 0
#define DOUBLE_KIND 1

typedef struct{
    int kind; //tag

    union{
        int i;
        double d;
    }u;
}Number;

void print_number(Number n);

int main(void){
    Number n;
    n.kind = DOUBLE_KIND;
    n.u.d = 10.33;
    print_number(n);
}

void print_number(Number n){
    if(n.kind == INT_KIND)
        printf("%d",n.u.i);
    else
        printf("%g",n.u.d);
}