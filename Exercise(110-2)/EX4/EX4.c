#include <stdio.h>
#include <math.h>


#define TRUE 1
#define FALSE 0
#define MAX_INPUT 100
typedef int BOOL;

// #define DEBUG


/* polynomial calculator use struct */

struct poly{
    int term;
    int times;
    int cof[MAX_INPUT];
    int exp[MAX_INPUT];
    int num[MAX_INPUT];
};

void ShowPoly(const struct poly *p);
void Eval(const struct poly *p);

int main(void){
    BOOL term_valid = FALSE;
    BOOL times_valid = FALSE;
    BOOL num_valid = FALSE;

    //Create poly
    struct poly *ptr = malloc(sizeof(struct poly));
    // struct poly Mypoly;
    // struct poly *ptr = &Mypoly;

    //Check input_term
    do{
        fprintf(stderr, "Enter the number of terms: ");
        scanf("%d", &ptr->term);
        if(ptr->term > 0)
            term_valid = TRUE;
        if(ptr->term < 1)
            printf("The number must be greater than zero!\n");
    }while(term_valid == FALSE);


    //Check input_cof,exp
    fprintf(stderr, "Enter each term with cof and exp:\n");
    for(int i = 0; i < ptr->term ; i++){
        scanf("%d %d",&ptr->cof[i],&ptr->exp[i]);
    }

    ShowPoly(ptr);

    //Check times    
    fprintf(stderr, "How many times to calculate: ");
    do{
        scanf("%d", &ptr->times);
        if(ptr->times > 0)
            times_valid = TRUE;
        if(ptr->times < 1){
            printf("The number must be greater than zero!\n");
            fprintf(stderr, "How many times to calculate: ");
        }
    }while(times_valid == FALSE);

    //Check unknown number
    for(int i = 0; i < ptr->times ; i++){
        fprintf(stderr, "The unknown number x is:");
        num_valid = FALSE;
        do{
            scanf("%d",&ptr->num[i]);
            if(ptr->num[i] > 0)
                num_valid = TRUE;
            if(ptr->num[i] < 1){
                printf("The number must be greater than zero!\n");
                fprintf(stderr, "The unknown number x is:");
            }
        }while(num_valid == FALSE);
    }

    Eval(ptr);

    #ifdef DEBUG
        printf("===CHECK COF,EXP===\n");
        for(int i = 0; i < ptr->term ; i++){
            printf("cof:%d exp:%d",ptr->cof[i],ptr->exp[i]);
            printf("\n");
        }

        printf("===CHECK times===\n");
        printf("times:%d\n",ptr->times);

        printf("===CHECK unknown===\n");
        for(int i = 0; i < ptr->times ; i++){
            printf("unknown:%d",ptr->num[i]);
            printf("\n");
        }
    #endif
}

void ShowPoly(const struct poly *p){
    for(int i = 0;i < p->term ; i++){
        printf("%dx^%d ",p->cof[i],p->exp[i]);
        if(i == p->term - 1)
            printf("=\n");
        else
            printf("+ ");
    }
}

void Eval(const struct poly *p){
    for(int i = 0 ; i < p->times ; i++){
        int ans = 0;
        int num = p->num[i];
        for(int j = 0 ; j < p->term ; j++)
            ans += p->cof[j] * pow(num , p->exp[j]);
        printf("%d\n",ans);
    }
}