#include <stdio.h>
#include <string.h>

#define NUM_PLANTES 9

int main(int argc, char *argv[]){
    char *planets[] = {"Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune", "Pluto"};

    int i, j;
    for (i = 1; i < argc ; i++)
    {
        for (j = 0; j < NUM_PLANTES; j++)
        {
            if(strcmp(argv[i],planets[j]) == 0){
                printf("%s is planet %d\n", argv[i], j);
                break;
            }
            if(j == NUM_PLANTES - 1)
                printf("%s is not a planet\n", argv[i]);
        }
        
    }
    return 0;
}