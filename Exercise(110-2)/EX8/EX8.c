#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 20

typedef struct {
    int HP;
    int ATK;
    char NAME[MAX_LEN];
    char ATTR[MAX_LEN];
} Pokemon;

int compare_priority(Pokemon *Pokemon_A, Pokemon *Pokemon_B); //比較寶可夢屬性(Water數字最小，優先權最高)
void print_data(Pokemon *list, int num); 
int compare(const void *a, const void *b); //qsort的排序依據 

//替屬性設定權重 (最高->最低，數字越小越高)
enum ATTR {W = 0 , F , E , L , D};

/**
 * @brief _case : 控制目前排序依據的全域變數
 * 0 : HP排序
 * 1 : ATK排序
 * 2 : 字典排序
 * 3 : 屬性排序
 */
int _case = 0;

int main(void){
    int pokemon_num, case_num;
    scanf("%d %d",&pokemon_num, &case_num);

    // 創立寶可夢的結構陣列
    Pokemon *list = malloc(sizeof(Pokemon) * pokemon_num);

    // 讀入寶可夢資訊
    for(int i = 0 ; i < pokemon_num ; i++)
        scanf("%s %s %d %d",list[i].NAME, list[i].ATTR, &list[i].ATK, &list[i].HP);
   
    // print_data(list, pokemon_num);

    // 讀入當前CASE，將對應排序印出
    for(int i = 0 ; i < case_num ; i++){
        printf("Case #%d:\n", i+1);
        
        char case_name[MAX_LEN];
        scanf("%s", case_name);

        if(strcmp(case_name,"HP") == 0){
            _case = 0;
            qsort(list, pokemon_num, sizeof(Pokemon), compare);
            print_data(list, pokemon_num);
        }
        
        if(strcmp(case_name,"ATTACK") == 0){
            _case = 1;
            qsort(list, pokemon_num, sizeof(Pokemon), compare);
            print_data(list, pokemon_num);
        }

        if(strcmp(case_name,"NAME") == 0){
            _case = 2;
            qsort(list, pokemon_num, sizeof(Pokemon), compare);
            print_data(list, pokemon_num);
        }

        if(strcmp(case_name,"ATTRIBUTE") == 0){
            _case = 3;
            qsort(list, pokemon_num, sizeof(Pokemon), compare);
            print_data(list, pokemon_num);
        }
    }

    return 0;
}

int compare_priority(Pokemon *Pokemon_A, Pokemon *Pokemon_B){
    int A_priority = 0, B_priority = 0;
    switch (Pokemon_A->ATTR[0]){
        case 'W':
            A_priority = W;
            break;
        case 'F':
            A_priority = F;
            break;
        case 'E':
            A_priority = E;
            break;
        case 'L':
            A_priority = L;
            break;
        case 'D':
            A_priority = D;
            break;
    }
    switch (Pokemon_B->ATTR[0]){
        case 'W':
            B_priority = W;
            break;
        case 'F':
            B_priority = F;
            break;
        case 'E':
            B_priority = E;
            break;
        case 'L':
            B_priority = L;
            break;
        case 'D':
            B_priority = D;
            break;
    }
    return A_priority - B_priority;
}

void print_data(Pokemon *list, int num){
    for(int i = 0 ; i < num ; i++)
        printf("%s %s %d %d\n", list[i].NAME, list[i].ATTR, list[i].ATK, list[i].HP);
}

int compare(const void *a, const void *b){
    Pokemon *Pokemon_A = (Pokemon *)a;
    Pokemon *Pokemon_B = (Pokemon *)b;

    if(_case == 0)
        return Pokemon_A->HP - Pokemon_B->HP;   //小->大
    if(_case == 1)
        return Pokemon_B->ATK - Pokemon_A->ATK; //大->小
    if(_case == 2)
        return strcmp(Pokemon_A->NAME, Pokemon_B->NAME); //字典排序
    if(_case == 3){
        int difference = compare_priority(Pokemon_A, Pokemon_B);
        if(difference > 0)
            return difference;
        if(difference < 0)
            return difference;
        if(difference == 0)
            return Pokemon_A->HP - Pokemon_B->HP;
    }

    return 0;
}

/** 
 * @brief qsort的compare回傳值意義
 * int compare(const void* p1, const void* p2) 
 * <0 The element pointed by p1 goes before the element pointed by p2
 * =0 The element pointed by p1 is equivalent to the element pointed by p2
 * >0 The element pointed by p1 goes after the element pointed by p2
 */

/**
 * @brief 參考: qsort with an array of structs
 * https://stackoverflow.com/questions/6105513/need-help-using-qsort-with-an-array-of-structs
 */