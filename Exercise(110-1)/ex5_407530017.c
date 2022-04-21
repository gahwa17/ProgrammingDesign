#include <stdio.h>

int main(void){
    int blood = 10, strengh = 2, keep_play = 0;
    int village; //是否待在村莊
    printf("Welcome, Adventurer!\n");
    printf("(Line:6) Do you want to go to our village first (1: Yes; 0: No)? ");
    scanf("%d", &village);

    do{
        int result;  //輸贏
        int monster;
        int choice,sword=0;
        while(village == 1){
            printf("What do you want to do in our village (1: buy a magical sword;2: go to the bar; 3: leave the village)?");
            scanf("%d", &choice);
            switch(choice){
                case 1: //1:買劍補力量
                    if(sword==1)
                        printf("You already brought a sword.\n");
                    else{
                        strengh++;
                        printf("Nice sword! Now you have %d strength!\n",strengh);
                        sword = 1;
                    }
                    break;
                case 2: //2:酒吧補血
                    if(blood == 10)
                        printf("Your blood is full. You don't need a beer.\n");
                    else{
                        blood++;
                        printf("Nice beer! Now you have %d blood!\n",blood);
                    }
                    break;
                case 3: //離開村莊
                    village = 0;
                    printf("You are welcome to come back anytime!\n");
                    break;
                default:
                    printf("Invalid action! 1: buy a magical sword; 2: go to the bar; 3:leave the village.\n");
                    break;
            }
        }

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

        if(keep_play==0){
            printf("We will miss you. Bye!");
            break;
        }

        //若要繼續玩，要先去村莊嗎?
        printf("(Line:78) Do you want to go to our village first (1: Yes; 0: No)? ");
        scanf("%d",&village);


        if(blood < 0){
            printf("You Dead. Bye!");
            break;
        }

    } while (keep_play == 1);
}