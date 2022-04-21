#include <stdio.h>
//完成!!! 是long long的scanf語法沒有記熟
int main(){
    int ans[10] = {0};
    long long num;
    scanf("%lld", &num);
    while(num>=1){
        int index = num % 10;
        num = num / 10;
        ans[index] += 1;
    }
    for (int i = 0; i < 10;i++)
        printf("%d ", i);
    printf("\n");
    for (int i = 0; i < 10;i++)
        printf("%d ", ans[i]);    
}