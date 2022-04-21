#include <stdio.h>

int main(void){
    //Create Matrix
    int row,col;
    int Vrow,Vcol;
    int Mrow,Mcol;
    printf("Input the number of row and column for the map:\n");
    scanf("%d %d", &row, &col);
    char matrix[row][col];
    
    //Init
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            matrix[i][j] = '.';
        }
    }

    //Set village
    printf("Input the row and column for the village location:\n");
    scanf("%d %d", &Vrow, &Vcol);
    while(Vrow > (row - 1) || Vcol > (col - 1) || Vrow < 0 || Vcol < 0){     //Out of range
        printf("the location is outside the map\n");
        printf("Input the row and column for the village location:\n");
        scanf("%d %d", &Vrow, &Vcol);
    }
    matrix[Vrow][Vcol] = 'v';

    //Set monster
    int monster = (row / 10) + (row % 10);
    printf("You need to assign location for %d monsters in total\n",monster);
    for (int i = 0; i < monster; i++){
        printf("Input the row and column for monster %d:\n", i);
        scanf("%d %d", &Mrow, &Mcol);
        
        //Range check
        if(Mrow > (row - 1) || Mcol > (col - 1) || Mrow < 0 || Mcol < 0){     
            printf("the location is outside the map\n");
            i--;
        }

        //Occupied cheack
        else if(matrix[Mrow][Mcol] == 'm' || matrix[Mrow][Mcol] == 'v'){
            printf("the location is occupied\n");
            i--;
        } else {
            matrix[Mrow][Mcol] = 'm';
        }
    }

    //Print Map
    printf("=== MAP ===\n");
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("=== MAP ===");
    return 0;
}