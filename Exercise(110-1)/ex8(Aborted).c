#include <stdio.h>
#include <string.h> 

int row,col;
int Vrow,Vcol;
int Mrow,Mcol;
int Prow,Pcol;
char map[100][100];

void create_map(char *ptr_map,int *ptr_row , int *ptr_col);
void print_map(char *ptr_map, int *ptr_row, int *ptr_col);
void setup_village(char *ptr_map, int *ptr_row, int *ptr_col);
void setup_monster(char *ptr_map, int *ptr_row, int *ptr_col);
int check_boundary(int *ptr_row , int *ptr_col,int check_row,int check_col);
int check_availability(char *ptr_map,int check_row,int check_col);
void setup_player(char *ptr_map, int *ptr_row, int *ptr_col);
void go_up();
void go_down();
void go_left();
void go_right();
void check_move();

int main(void){
    char *ptr_map = &map[0][0];
    int *ptr_row = &row;
    int *ptr_col = &col;
    int *ptr_Prow = &Prow;
    int *ptr_Pcol = &Pcol;
    int choice;
    create_map(ptr_map,ptr_row,ptr_col);
    setup_village(ptr_map, ptr_row, ptr_col);
    setup_monster(ptr_map, ptr_row, ptr_col);
    print_map(ptr_map, ptr_row, ptr_col);

    //是否重建地圖?
    printf("[1] Create a new map [2] Start travel the map:");
    scanf("%d", &choice);
    while(choice==1){
        create_map(ptr_map,ptr_row,ptr_col);
        setup_village(ptr_map, ptr_row, ptr_col);
        setup_monster(ptr_map, ptr_row, ptr_col);
        print_map(ptr_map, ptr_row, ptr_col);
        printf("[1] Create a new map [2] Start travel the map:");
        scanf("%d", &choice);
        if(choice==2)
            break;
    }

    //玩家區塊
    setup_player(ptr_map, ptr_row, ptr_col);
    print_map(ptr_map, ptr_row, ptr_col);
    while(1){
        printf("[1] go up [2] go down [3] go right [4] go left [5] exit:");
        int move;
        scanf("%d", &move);
        switch(move){
            case 1:
                go_up(*ptr_map, *ptr_Prow, *ptr_Pcol,*ptr_row, *ptr_col);
                break;
            case 2:
                go_down(*ptr_map, *ptr_Prow, *ptr_Pcol,*ptr_row, *ptr_col);
                break;
            case 3:
                go_right(*ptr_map, *ptr_Prow, *ptr_Pcol,*ptr_row, *ptr_col);
                break;
            case 4:
                go_left(*ptr_map, *ptr_Prow, *ptr_Pcol,*ptr_row, *ptr_col);
                break;

        }
        if(move==5)
            break;
    }
    

    return 0;
}

//village & monster : location range check
int check_boundary(int *ptr_row , int *ptr_col,int check_row,int check_col){
    //超出範圍，回傳0
    if(check_row > (*ptr_row - 1) || check_col > (*ptr_col - 1) || check_row < 0 || check_col < 0){
        printf("the location is outside the map\n");
        return 0;
    }
    else
        return 1;
}

//monster : occupied check
int check_availability(char *ptr_map,int check_row,int check_col){
    //被佔領過，回傳0
    if(map[check_row][check_col] == 'm' || map[check_row][check_col] == 'v'){
        printf("the location is occupied\n");
        return 0;
    }
    else
        return 1;   
}

void create_map(char *ptr_map,int *ptr_row , int *ptr_col){
    printf("Input the number of row and column for the map:\n");
    scanf("%d %d", ptr_row, ptr_col);
    for (int i = 0; i < *ptr_row; i++){
        for (int j = 0; j < *ptr_col; j++){
            map[i][j] = '.';
        }
    }
    return;
}

void print_map(char *ptr_map, int *ptr_row, int *ptr_col){
    printf("=== MAP ===\n");
    for (int i = 0; i <  *ptr_row ; i++){
        for (int j = 0; j < *ptr_col; j++){
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
    printf("=== MAP ===\n");
}

void setup_village(char *ptr_map, int *ptr_row, int *ptr_col){
    printf("Input the row and column for the village location:\n");
    scanf("%d %d", &Vrow, &Vcol);

    while(!(check_boundary(ptr_row, ptr_col, Vrow,Vcol))){ //Out of range 
        printf("Input the row and column for the village location:\n");
        scanf("%d %d", &Vrow, &Vcol);
    }
    map[Vrow][Vcol] = 'v';
}

void setup_monster(char *ptr_map, int *ptr_row, int *ptr_col){
    int monster = (*ptr_row / 10) + (*ptr_row % 10);
    printf("You need to assign location for %d monsters in total\n",monster);
    for (int i = 0; i < monster; i++){
        printf("Input the row and column for monster %d:\n", i);
        scanf("%d %d", &Mrow, &Mcol);
        
        //Range check
        if(!(check_boundary(ptr_row, ptr_col, Mrow, Mcol))){     
            i--;
        }

        //Occupied cheack
        else if(!(check_availability(ptr_map, Mrow, Mcol)))
            i--;
        else
            map[Mrow][Mcol] = 'm';
    }
}

void setup_player(char *ptr_map, int *ptr_row, int *ptr_col){
    printf("Input the row and column for player:\n");
    scanf("%d %d", &Prow, &Pcol);
    for (;;){
        if(check_availability(ptr_map, Prow, Pcol) && (check_boundary(ptr_row, ptr_col, Prow, Pcol)))
            break;
        else{
            printf("Input the row and column for player:\n");
            scanf("%d %d", &Prow, &Pcol);
        }
    }
    map[Prow][Pcol] = 'p';

}

void go_up(char *ptr_map, int *ptr_Prow, int *ptr_Pcol,int *ptr_row, int *ptr_col){
    map[*ptr_Prow][*ptr_Pcol] = '.';
    map[*ptr_Prow][*ptr_Pcol-1] = 'p';
    print_map(ptr_map, ptr_row, ptr_col);
}
void go_down(char *ptr_map, int *ptr_Prow, int *ptr_Pcol,int *ptr_row, int *ptr_col){
    map[*ptr_Prow][*ptr_Pcol] = '.';
    map[*ptr_Prow][*ptr_Pcol+1] = 'p';
    print_map(ptr_map, ptr_row, ptr_col);
}
void go_left(char *ptr_map, int *ptr_Prow, int *ptr_Pcol,int *ptr_row, int *ptr_col){
    printf("map1");
    printf("ptr_Prow:%d",*ptr_Prow);
    printf("ptr_Pcol:%d",*ptr_Pcol);

    map[*ptr_Prow][*ptr_Pcol] = '.';
    map[*ptr_Prow-1][*ptr_Pcol] = 'p';
    printf("map2");
    print_map(ptr_map, ptr_row, ptr_col);
}
void go_right(char *ptr_map, int *ptr_Prow, int *ptr_Pcol,int *ptr_row, int *ptr_col){
    map[*ptr_Prow][*ptr_Pcol] = '.';
    map[*ptr_Prow+1][*ptr_Pcol] = 'p';
    print_map(ptr_map, ptr_row, ptr_col);
}
