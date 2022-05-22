#include <stdio.h>

/**
 * 作業目標
 * 用Bitwise(位元運算)，使16進位前8與後8個位元swap
 */

unsigned short swap_bytes(unsigned short i){
    unsigned short int left, right, ans;

    left = i << 8;
    right = i >> 8;
    ans = left | right;

    // printf("%08hx\n", i);
    // printf("%08hx\n", left);
    // printf("%08hx\n", right);

    return ans;
}

int main(void){
    unsigned short int i, ans;

    scanf("%hx", &i);

    ans = swap_bytes(i);
    printf("%hx\n", ans);
}


