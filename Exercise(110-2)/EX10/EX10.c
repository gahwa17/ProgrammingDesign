#include <stdio.h>
#include <stdlib.h>

#define DEBUG

//印出二進位(檢查用)
void printBin(int k) {
    int output[8] = {0};
    for(int i = 0 ; k > 0 ; i++){    
        output[i]= k % 2;    
        k = k/2;    
    }    
    for(int j = 7; j >=0 ; j--)
        printf("%d", output[j]);
    putchar('\n');
}

void binary_add(unsigned char *table, int index, int pos){
    //frequency(登入次數): 將user所佔bits，table[index]左移後，再用%4只取二進位最後兩位數，來判斷該使用者的登入次數
    unsigned short frequency = (table[index] >> (pos*2)) % 4;

    //(檢查用)查看該user的目前的登入次數為多少
    #ifdef DEBUG
        printf("Before add 1: frequency(Bin)=");
        printBin(frequency);
        printf("Before add 1: frequency = %d\n", frequency);
    #endif

    //若user的登入次數到達3，Goodbye
    if(frequency == 3)
        printf("GOOD BYE\n");
    //若user的登入次數尚未到達3，往下繼續進行
    else{
        printf("PASS\n");
        int carry = 0; //紀錄進位
        //將8bits以2bits分成4位使用者，左->右(pos:0->4)，根據不同的位置(pos)，執行+1的動作
        switch (pos){
            case 0:
                carry = (table[index] & 1) << 1;
                table[index] = table[index] ^ 1;
                break;
            case 1:
                carry = (table[index] & 4) << 1;
                table[index] = table[index] ^ 4;
                break;
            case 2:
                carry = (table[index] & 16) << 1;
                table[index] = table[index] ^ 16;
                break;
            case 3:
                carry = (table[index] & 64) << 1;
                table[index] = table[index] ^ 64;
                break;    
            default:
                break;
        }
        //處理進位
        table[index] = table[index] ^ carry;

        //(檢查用)次數+1後，查看使用者目前所占用的bits之二進位
        #ifdef DEBUG
            printf("After add 1: user's bits=");
            printBin(table[index]);
        #endif

    }
}

int main(void) {
    int user_num, table_size, index, position, user_id;
    scanf("%d", &user_num);
    table_size = user_num/4;

    unsigned char *table = malloc(sizeof(char) * table_size);

    //初始化table，使其二進位全為0
    for(int i = 0 ; i < table_size ; i++)
        table[i] = 0;
    while(scanf("%d", &user_id) != EOF){
        //user範圍:0~user_num，超過為非法輸入
        if(user_id > user_num - 1)
            printf("Invalid user id.\n");
        else{
            index = user_id / 4;
            position = user_id % 4;
            
            //(檢查用)查看userid、index:在整個字元陣列table中位於哪一格元素、position
            #ifdef DEBUG
                printf("id:%d, index:%d, pos:%d\n", user_id, index, position);
            #endif

            binary_add(table, index, position);
        }
    }
}