#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_LEN 100

/* Longest Common Prefix */ 

int main (void){
    int case_num = 0; // 1->case sense ; 2->case insense
    int word_num = 0;

    scanf("%d",&case_num);
    scanf("%d",&word_num);

    char input[word_num][MAX_LEN]; //Input words

    char lcs[MAX_LEN]; //save our longest common prefix
    int lcs_index = 0; //control lcs array's index
    memset(lcs,'\0',7);//Init array with '\0'

    //scanf in.txt to input[]
    for(int i = 0 ; i < word_num ; i++){
        scanf("%s",input[i]);
        // printf("[%d]: %s\n",i,input[i]);
    }

    //if case insense, words to lower
    if(case_num == 2){
        for(int i = 0; i < word_num ; i++){
            for(int j = 0 ; j < strlen(input[i]) ; j++)
                input[i][j] = tolower(input[i][j]);
        }
    }

    int flag = 1;
    for(int i = 0 ; i < sizeof(input)/sizeof(input[0]) ; i++){
        if(flag == 0)
            break;
        // printf("Run %d\n",i);
        char cmp_ch;
        char cur_ch;
        for(int j = 0 ; j < sizeof(input)/sizeof(input[0]);j++){
            cur_ch = input[j][i];
            // printf("[%d][%d]:",i,j);
            // printf("%c\n",cur_ch); 
            if(j == 0)
                cmp_ch = input[j][i];
            else{
                if(cmp_ch != cur_ch){
                    // printf("%c is differ from %c\n",cmp_ch,cur_ch);
                    flag = 0;
                    break;
                }
            }
        }
        if(flag == 1){
            // printf("Add %c to lcs\n",cur_ch);
            lcs[lcs_index++] = cur_ch;
        }
    }

    // printf("len: %d\n",strlen(lcs));
    if(strlen(lcs) > 0)
        printf("%s",lcs);
    else
        printf("No longest common prefix"); 
}
