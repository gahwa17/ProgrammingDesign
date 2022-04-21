#include <stdio.h>

int main(void){
    int input = 0;
    printf("Enter:");
    scanf("%d",&input);

    int bill_20 = input / 20;
    printf("$20 bills:%d\n",bill_20);
    input = input % 20;

    int bill_10 = input / 10;
    printf("$10 bills:%d\n",bill_10);
    input = input % 10;

    int bill_5 = input / 5;
    printf("$5 bills:%d\n",bill_5);
    input = input % 5;

    printf("$1 bills:%d\n",input);

    return 0;
}