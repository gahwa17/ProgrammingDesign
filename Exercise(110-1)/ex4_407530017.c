#include <stdio.h>

int main(void){
    int blood = 10, strengh = 2, keep_play = 1;
    printf("Welcome, Adventurer!\n");

    do{
        int result;  //輸贏
        int monster;

        //打怪階段
        printf("You have %d blood and %d strength.\n", blood, strengh);
        printf("Please choose which monster (1 to 4) you want to fight:");
        scanf("%d", &monster);

        //依照選擇的怪物等級，在此決定輸贏結果
        switch(monster){ 
            case 1:
            case 2: 
            case 3:
            case 4:
                printf("You are fighting Monster %d!\n",monster);
                result = strengh > monster ? 1 : 0; //若力量>怪物，則贏(1)，否則輸(0)
                break;
            default:
                printf("No such monster, please enter 1 to 4 to choose the monster.\n");
                result = 2;
                break;
        }
        if(result==1){ //打贏，力量+1
            printf("You win!\n");
            strengh += 1;
        }
        else if(result==0){ //打輸，血-怪物
            printf("You lose!\n");
            blood -= monster;
        }
        //是否要繼續玩?
        printf("Do you want to go on your adventure (1: Yes; 0: No) ?:");
        scanf("%d",&keep_play);

        if(keep_play == 0){
            printf("We will miss you. Bye!");
            break;
        }

        if(blood < 0){
            printf("You Dead. Bye!");
            break;
        }
    } while (keep_play == 1);
}