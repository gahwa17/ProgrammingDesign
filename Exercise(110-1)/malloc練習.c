#include <stdio.h>
#include <stdlib.h>

void print_array(int *p,int n){
    int *i;
    for (i = p; i < p + n; i++){
        printf("%d ", *i);
    }
}

int main(){
    int *array;
    int n = 4;
    array = malloc(n * sizeof(int));
    printf("The size of array:%llu\n", sizeof(*array));

    array[0] = 1;
    array[1] = 2;
    array[2] = 3;
    array[3] = 4;

    print_array(array, n);
    free(array);

}
