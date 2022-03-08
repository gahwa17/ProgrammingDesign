#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define MAX_PATN 100
#define MAX_ARC 4095

void read_line();
void read_pattern();  //read pattern,replacement and parameter
int check_parameter(); // check whether parameter is valid
void read_article();

int main(void){
    char arc[MAX_ARC];
    char *old;
    char *new;
    char *para;

    //Init article
    for (int i = 0; i < MAX_ARC;i++)
        arc[i] = '\0';

    fprintf(stderr, "Enter pattern, replacement, and at most one parameter: ");

    char pattern[80];
    char delim[10] = " !?_\n\t,.";

    read_line(pattern, 100);
    
    old = strtok(pattern, delim);
    new = strtok(NULL, delim);
    para = strtok(NULL, delim);

    printf("old:%s\n", old);
    printf("new:%s\n", new);
    printf("para:%s\n", para);

    int oldlen = strlen(old);
    int newlen = strlen(new);

    printf("oldlen: %d\n", oldlen);
    printf("newlen: %d\n", newlen);


    
    //check parameter
    if(check_parameter(para) == FALSE)
        fprintf(stderr, "The input format: string1 string2 [parameter]");
    else{
        fprintf(stderr, "Enter the article: ");

        while(fgets(arc,MAX_PATN,stdin) != NULL){
            printf("%s\n", arc);
            /*
            char skip[10] = " !?_\n\t,.";
            char *token;
            char *needle;
            token = strtok(arc, skip);

            while(token != NULL){
                printf("cur token is: %s\n", token);
                int cnt = 0;
                int tokenlen = strlen(token);

                needle = strstr(token, old);
                
                if(needle != NULL){
                    printf("cur needle is: %s\n", needle);
                    //count how many oldword exist in every token 
                    for (int i = 0; i < strlen(token); i++){
                        if(strstr(&token[i],old) == &token[i]){
                            cnt++;
                            i = i + oldlen;
                        }
                    }
                    printf("cnt : %d\n", cnt);

                    //create new str to replace old with new
                    int reslen = tokenlen + (newlen - oldlen) * cnt + 1;

                    char res[reslen];
                    int i = 0;
                    char *ptr = token;

                    while(i < reslen){
                        for ( ; ptr < needle; ptr++){
                        res[i] = *ptr;
                        i++;
                        }
                        for (int j = 0; j < newlen;j++){
                        res[i] = new[j];
                        i++;
                        }
                        
                        for (int k = 0; k < oldlen;k++)
                        ptr++;

                        for ( ; *ptr!='\0' ; ptr++){
                        res[i] = *ptr;
                        i++;
                        }
                    }
                    
                    res[reslen - 1] = '\0';
                    printf("res: %s\n", res);
                }
                token = strtok(NULL, skip);
            }
            */
        }
    }
}

//Discard
void read_pattern(char *old,char *new,char *para){
    char pattern[80];
    char delim[10] = " !?_\n\t,.";

    read_line(pattern, 100);
    
    old = strtok(pattern, delim);
    new = strtok(NULL, delim);
    para = strtok(NULL, delim);

    printf("old:%s\n", old);
    printf("new:%s\n", new);
    printf("para:%s\n", para);
}

void read_line(char str[], int n)
{
    int ch, i = 0;
    while ((ch = getchar()) != '\n'){
        if (i < n)
        str[i++] = ch;
        str[i] = '\0'; /* terminates string */
    }
}

int check_parameter(char para[]){
    int flag = TRUE;
    if(para == NULL)
        return TRUE;
    else{
        if(strlen(para) != 2 || para[0] != '-' || para[1] != 'i')
            flag = FALSE;
    }
    return flag;
}

void read_article(char str[]){
    int ch;
    while ( (ch = getchar()) != EOF){
        while(ch != '\n'){

        }
    }
}