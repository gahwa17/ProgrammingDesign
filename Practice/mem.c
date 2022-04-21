#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){
    char source[] = "Tutorial";
    char destination[] = "Programiz";

    // copy all bytes of destination to source
    memcpy(destination, source, sizeof(source));
    puts (destination); // destination: Tutorial

    char str[] = "memmove can be very useful......";
    //memmove(void *dest, void *src , size_t num); copy num of src to dest
    memmove (str+20,str+14,11); 
    puts (str);  // str: memmove can be very very useful.
}



