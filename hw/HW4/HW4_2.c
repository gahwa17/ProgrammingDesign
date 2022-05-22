#include <stdio.h>

#define PI 3.14

int (*x (int a) ) [5];

/**
 * 作業4_2 : 觀念題
 */

int (*x (int input) )[5]{
    int (*ans)[5]; //pointer to an array of integers
    int y[5] = {1,2,3,4,5};
    ans = &y;
    return ans;
}


int f(int i){
    static int j = 0;
    return i * j++;
}

int main(void){
    // 第一大題: 何種寫法合法? (PI為巨集)
    char c = 65;
    // static int i = 5, j = i * i; (static變數宣告不能多個)
    double d = 2 * PI;
    double angles [ ] = { 0 , PI / 2, PI, 3 * PI / 2};


    //第二大題 : 涵式的複雜宣告

    //2-2 : int (*x (int) ) [5];
    int (*ans_3)[5];
    ans_3 = x(10);


    // 第四題 : static應用
    int ans_4 = f(10); // 第一次呼叫f(10)，答案為0，因為j=0
    printf("%d\n", ans_4);
    ans_4 = f(10);
    printf("%d\n", ans_4); // 第二次呼叫f(10)，答案為10，因為j=1，以此類推第三次呼叫f(10)，答案為20(j=2)

}

