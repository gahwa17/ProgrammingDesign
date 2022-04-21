#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    char *s,*s_r;

    s = (char*) malloc(3+1);
    strcpy(s,"abc");

    printf("===Before realloc===\n");
    printf("String = %s, Addr = %u\n", s, s);

    s_r = (char *) realloc(s,5+1);
    strcat(s,"def");
    
    printf("===After realloc===\n");
    printf("String = %s, Addr = %u\n", s_r, s_r);
    printf("String = %s, Addr = %u\n", s, s);
}