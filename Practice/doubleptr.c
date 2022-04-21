#include <stdio.h>
#include <stdlib.h>

void printf_arr(int *target,int n);
void printf_matrix(int **matrix, int m, int n);

int main(void){
    int *arr;
    int n = 4;

    arr = malloc(n * sizeof(*arr)); // malloc(n * sizeof(int))
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;

    printf("arr: \n");
    printf_arr(arr,n);

    int **matrix;
    int m = 2;
    matrix = malloc(m * sizeof(*matrix));
    matrix[0] = arr;
    matrix[1] = (int[]){5,6,7,8};

    printf("matrix: \n");
    printf_matrix(matrix, m ,n);

    free(arr);
    free(matrix);
}

void printf_arr(int *target, int n){
    int *tmp;
    for(tmp = target ; tmp < target + n ; tmp++){
        printf("%d ",*tmp);
    }
    printf("\n");
}

void printf_matrix(int **matrix, int m, int n){
    int **tmp;
    for(tmp = matrix ; tmp < matrix + m ; tmp++){
        printf_arr(*tmp, n);
    }
}