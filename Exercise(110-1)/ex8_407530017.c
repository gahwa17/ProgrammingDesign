#include <stdio.h>
#include <string.h> 

#define False 0
#define True  1


int row,col;
int Vrow,Vcol;
int Mrow,Mcol;
int Prow,Pcol;
char map[100][100];

void create_map();
void print_map();
void setup_village();
void setup_monster();
int check_boundary();
int check_availability();
void setup_player();
void go_up();
void go_down();
void go_left();
void go_right();
int check_move();

int main(void){
    int choice;
    create_map();
    setup_village();
    setup_monster();
    print_map();

    //是否重建地圖?
    printf("[1] Create a new map [2] Start travel the map: ");
    scanf("%d", &choice);
    while(choice==1){
        create_map();
        setup_village();
        setup_monster();
        print_map();
        printf("[1] Create a new map [2] Start travel the map: ");
        scanf("%d", &choice);
        if(choice==2)
            break;
    }

    //玩家區塊
    setup_player();
    print_map();
    while(1){
        printf("[1] go up [2] go down [3] go right [4] go left [5] exit: ");
        int move;
        scanf("%d", &move);
        switch(move){
            case 1:
                go_up();
                break;
            case 2:
                go_down();
                break;
            case 3:
                go_right();
                break;
            case 4:
                go_left();
                break;
        }
        if(move==5){
            printf("Bye!");
            break;
        }
    }
    

    return 0;
}

//village & monster : location range check
int check_boundary(int check_row,int check_col){
    //超出範圍，回傳0
    if(check_row > (row - 1) || check_col > (col - 1) || check_row < 0 || check_col < 0){
        printf("the location is outside the map\n");
        return 0;
    }
    else
        return 1;
}

//monster : occupied check
int check_availability(int check_row,int check_col){
    //被佔領過，回傳0
    if(map[check_row][check_col] == 'm' || map[check_row][check_col] == 'v'){
        printf("the location is occupied\n");
        return 0;
    }
    else
        return 1;   
}

void create_map(){
    printf("Input the number of row and column for the map:\n");
    scanf("%d %d", &row, &col);
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            map[i][j] = '.';
        }
    }
    return;
}

void print_map(){
    printf("=== MAP ===\n");
    for (int i = 0; i <  row ; i++){
        for (int j = 0; j < col; j++){
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
    printf("=== MAP ===\n");
}

void setup_village(){
    printf("Input the row and column for the village location:\n");
    scanf("%d %d", &Vrow, &Vcol);
    
    //Out of range 
    while(!(check_boundary(Vrow,Vcol))){ 
        printf("Input the row and column for the village location:\n");
        scanf("%d %d", &Vrow, &Vcol);
    }
    map[Vrow][Vcol] = 'v';
}

void setup_monster(){
    int monster = (row / 10) + (row % 10);
    printf("You need to assign location for %d monsters in total\n",monster);
    for (int i = 0; i < monster; i++){
        printf("Input the row and column for monster %d:\n", i);
        scanf("%d %d", &Mrow, &Mcol);
        
        //Range check
        if(!(check_boundary(Mrow, Mcol))){     
            i--;
        }

        //Occupied cheack
        else if(!(check_availability(Mrow, Mcol)))
            i--;
        else
            map[Mrow][Mcol] = 'm';
    }
}

void setup_player(){
    printf("Input the row and column for player:\n");
    scanf("%d %d", &Prow, &Pcol);
    for (;;){
        if(check_availability(Prow, Pcol) && (check_boundary(Prow, Pcol)))
            break;
        else{
            printf("Input the row and column for player:\n");
            scanf("%d %d", &Prow, &Pcol);
        }
    }
    map[Prow][Pcol] = 'p';

}

void go_up(){
    map[Prow][Pcol] = '.';
    Prow--;
    if(check_move()==False){
        Prow++;
        return;
    }
    map[Prow][Pcol] = 'p';
    print_map();
}
void go_down(){
    map[Prow][Pcol] = '.';
    Prow++;
    if(check_move()==False){
        Prow--;
        return;
    }
    map[Prow][Pcol] = 'p';
    print_map();
}
void go_left(){
    map[Prow][Pcol] = '.';
    Pcol--;
    if(check_move()==False){
        Pcol++;
        return;
    }
    map[Prow][Pcol] = 'p';
    print_map();
}
void go_right(){
    map[Prow][Pcol] = '.';
    Pcol++;
    if(check_move()==False){
        Pcol--;
        return;
    }
    map[Prow][Pcol] = 'p';
    print_map();
}

int check_move(){
    if(Prow > (row - 1) || Pcol > (col - 1) || Prow < 0 || Pcol < 0){
        printf("You can't go there\n");
        return False;
    }
    if(map[Prow][Pcol] == 'm' || map[Prow][Pcol] == 'v'){
        printf("You can't go there\n");
        return False;
    }
    return True;
}
