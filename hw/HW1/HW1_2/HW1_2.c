#include <stdio.h>
#include <string.h>

#define MAX 100000

void lower(char str[]);
void upper(char str[]);
void towave(char str[]);

int main(void){
    char str[MAX];
    int act = 0;
    scanf("%s",str);
    scanf("%d", &act);
    switch(act){
        case 1:
            upper(str);
            break;
        case 2:
            lower(str);
            break;
        case 3:
            towave(str);
            break;
        default: 
            printf("FAILED");
    }
    printf("%s",str);
}

void lower(char str[]){
    for(char* ptr = str; *ptr!='\0'; ptr++){
        char ch = *ptr;
        if(ch > 65 && ch < 91)
            *ptr = *ptr - 'A' + 'a';
    }
}

void upper(char str[]){
    for(char* ptr = str; *ptr!='\0'; ptr++){
        char ch = *ptr;
        if(ch > 96 && ch < 123){
            *ptr = *ptr - 32;
        }
    }
}

void towave(char str[]){
    int len = strlen(str);
    //ToUpper
    for (int i = 0; i < len; i+=2){
        if(str[i] > 96 && str[i] < 123){
            str[i] = str[i] - 32;
        }
    }
    //ToLower
    for (int i = 1; i < len; i+=2){
        if(str[i] > 65 && str[i] < 91)
            str[i] = str[i] - 'A' + 'a';
    }
}