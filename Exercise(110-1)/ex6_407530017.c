#include <stdio.h>

int main(void){
    printf("Enter an expression: ");
    char opr,ch;                    //運算元
    int isInvalid = 0;              //是否為合法的運算式
    float res, opd;                 //暫存運算結果, 新讀入的運算子
    scanf("%f",&res);
    while((ch = getchar())!= EOF && ch != '\n' && isInvalid != 1){
        opr = ch;                   //運算元(+-*/)
        scanf("%f",&opd);           //數字
        
        //檢查用
        printf("res: %.2f\n", res); 
        printf("opr: %c\n", opr);
        printf("opd: %.2f\n", opd);

        switch(opr){
            case '+':
                res += opd;
                opd = 0;
                break;
            case '-':
                res -= opd;
                break;
            case '*':
                res *= opd;
                break;
            case '/':
                if(opd == 0)        //Divided by zero
                    isInvalid = 1;        
                res /= opd;
                break;
        }
    }
    if(isInvalid)              //Divided by zero
        printf("Can't Divided by zero\n");
    else
        printf("Value of expression: %.2f", res);

    return 0;
}