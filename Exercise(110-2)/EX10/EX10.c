#include <stdio.h>
#include <stdlib.h>

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

int _pow(int x, int exp){
    if(exp == 0)
        return 1;
    else{
        int ans = x;
        for(int i = 1 ; i < exp ; i++)
            ans = ans * x;
        return ans;
    }
}

int binary_add(unsigned char *table, int offset){
    int sum[3] = {0};
    int carry = 0, frequency = 0;

    // 抓到position所指位置的兩個bits
    int bits = table[0] >> offset;

    // sum[2] = table[pos+1] ^ 1 ^ carry;
    // carry = ((table[pos+1] & 1) | (table[pos+1] & carry)) | (1 & carry);

    // sum[1] = table[pos] ^ 0 ^ carry;
    // carry = ((table[pos] & 0) | (table[pos] & carry)) | (0 & carry);

    sum[0] = carry;
    
    for(int i = 0 ; i<=2 ; i++)
        printf("%d\n", sum[i]);
    // putchar('\n');



    //計算登入次數(二進位轉十進位)
    for(int i = 0, exp = 2 ; i<=2 ; i++, exp--){
        // printf("%d * %d = %d\n", sum[i], _pow(2, exp), sum[i]*_pow(2, exp));
        int ans =  sum[i]*_pow(2, exp);
        frequency += ans;
    }
    printf("frequency: %d\n", frequency);

    return frequency;
}

int main(void) {
    int num, table_size,bits_amount, position, user, offset, frequency;
    scanf("%d", &num);
    table_size = num/4;
    bits_amount = table_size * 8;

    unsigned char *table = malloc(sizeof(char) * table_size);

    //初始化table，使其二進位全為0
    for(int i = 0 ; i < table_size ; i++)
        table[i] = 0;

    while(scanf("%d", &user) != EOF){
        offset = bits_amount - (user * 2);
        printf("user:%d pos:%d\n",user, offset);

        frequency = binary_add(table, position);

        if(frequency > 3)
            printf("GOOD BYE\n");
        else
            printf("PASS\n");
    }
}