#include <stdio.h>

void fun(int a){
    printf("a:%d\n", a);    
}

int main(void){
    //declare function pointer fun_ptr pointing to fun()
    void (*fun_ptr)(int) = &fun;
    // void (*fun_ptr)(int) = fun;

    //call fun() and print “a:20”
    (*fun_ptr)(20);
    // fun_ptr(20);
}