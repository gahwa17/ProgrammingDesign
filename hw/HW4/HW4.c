#include <stdio.h>

/**
 * 作業目標
 * 用Bitwise(位元運算)，使16進位前8與後8個位元swap
 */
// unsigned short	2 bytes	0 to 65,535

unsigned short swap_bytes(unsigned short i){
    unsigned short int left, right, ans;

    printf("%08hx\n", i);

    left = i << 8;
    right = i >> 8;
    ans = left | right;

    printf("hx: %08hx\n", left);
    printf("hx: %08hx\n", right);

    return ans;
}

int main(void){
    unsigned short int i, ans;

    scanf("%hx", &i);

    ans = swap_bytes(i);
    printf("hx: %hx\n", ans);
    printf("hu: %hu\n", ans);
}


