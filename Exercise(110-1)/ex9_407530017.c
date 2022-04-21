#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBER 9
#define True  1
#define False 0

void printsquare();
void p1_turn();
void p2_turn();
int check_valid();
int isWin();

char square[9]={'1','2','3','4','5','6','7','8','9'};
int p1, p2;
int left = 9; //剩餘有效格子
int end_flag = False; //是否分出輸贏

int main(void){
    printf("Player-1==>X\nPlayer-2==>O\n");
    printsquare();

    while (end_flag==False && left > 0){
        p1_turn();
        if(end_flag==True)
            break;
        p2_turn();
    }
    if(end_flag == False && left == 0)
        printf("Ended in a tie");
}

void p1_turn(){
    printf("player 1 ->");
    scanf("%d", &p1);
    printf("\nPlayer-1==>X\nPlayer-2==>O\n\n");
    if(square[p1-1] != 'O' && square[p1-1] != 'X'){
        square[p1-1]='X';
        left--;
    }
    printsquare();
    if(isWin()==True){
        printf("player-1 wins");
        end_flag = True;
    }
    // if(check_valid(p1) == True){
    //     square[p1-1]='X';
    //     printsquare();
    // }
    // else
    //     p1_turn();
}

void p2_turn(){
    //產生亂數
    srand(time(NULL));
    p2 = rand() % MAX_NUMBER + 1;

    printf("player 2 ->%d\n\n",p2);
    printf("Player-1==>X\nPlayer-2==>O\n\n");

    //格子合法判斷
    if(square[p2-1] != 'O' && square[p2-1] != 'X'){
        square[p2-1]='O';
        left--;
    }
    printsquare();
    if(isWin()==True){
        printf("player-2 wins");
        end_flag = True;
    }

    // if(check_valid(p2)==True){
    //     square[p2-1]='O';
    //     printsquare();
    // }
    // else
    //     p2_turn();
    
}

//判斷輸贏
int isWin(){
    if(square[0]==square[1] && square[1]==square[2])
        return True;
    else if(square[3]==square[4] && square[4]==square[5])
        return True;
    else if(square[6]==square[7] && square[7]==square[8])
        return True;
    else if(square[0]==square[3] && square[3]==square[6])
        return True;
    else if(square[1]==square[4] && square[4]==square[7])
        return True;
    else if(square[2]==square[5] && square[5]==square[8])
        return True;
    else if(square[0]==square[4] && square[4]==square[8])
        return True;
    else if(square[2]==square[4] && square[4]==square[6])
        return True;
    else
        return False;
}

// int check_valid(int check_position){
//     if(square[check_position] == 'O' || square[check_position] == 'X'){
//         printf("You can't write in here!");
//         return False;
//     }
//     else
//         return True;
// }

//印九宮格
void printsquare(){
    for (int i = 0; i < 9;i++){
        if((i+1) % 3 == 0 && i != 8){
            printf("%c ", square[i]);
            printf("\n");
            printf("__  __  __\n");
        }
        else{
            printf("%c ", square[i]);
            if(i!=8)
                printf("| ");
        }  
    }
    printf("\n\n");
}