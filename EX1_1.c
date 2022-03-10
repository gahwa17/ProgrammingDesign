#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0
#define MAX_PATN 100
#define MAX_ARC 4095

int check_str();       // check whether pattern is valid
int check_parameter(); // check whether 3th parameter is valid

int main(void){
    char pattern[MAX_PATN + 1];
    char arc[MAX_ARC + 1];
    char delim[10] = " !?_\n\t,."; //delim of pattern

    char *old;
    char *new;
    char *para;

    fprintf(stderr, "Enter pattern, replacement, and at most one parameter: \n");

    fgets(pattern, MAX_PATN, stdin);

    old = strtok(pattern, delim);
    new = strtok(NULL, delim);
    para = strtok(NULL, delim);


    if(strtok(NULL,delim)!=NULL || check_str(new) == FALSE || check_parameter(para) == FALSE)
        printf("The input format: string1 string2 [parameter]");
    else{

        int oldlen = strlen(old);
        int newlen = strlen(new);

        // printf("oldlen: %d\n", oldlen);
        // printf("newlen: %d\n", newlen);

        fprintf(stderr, "Enter the article: \n");

        while(fgets(arc,MAX_ARC,stdin) != NULL){

            //Case insensitive : change old tolowercase
            if(para != NULL){
                int i = 0;
                while (old[i]){
                    old[i] = tolower(old[i]);
                    i++;
                }
                // printf("new old:%s\n", old);
            }
            
            int arclen = strlen(arc);
            arc[arclen] = '\0';

            // printf("cur's arc: %s\n", arc);

            //filter special char
            char article_delim[MAX_ARC];
            for(int i = 0; i < MAX_ARC; i++)
				article_delim[i] = '\0';

            int j = 0;
            for (int i = 0; i < arclen; i++){
                if (isalnum(arc[i]) == 0 && arc[i] != '-'){
                    // printf("%c ", arc[i]);
                    article_delim[j] = arc[i];
                    j++;
                }
            }
            // printf("\ncur's article_delim: %s\n", article_delim);

            
            char *token;
            char *needle;
            token = strtok(arc, article_delim);
            

            while(token != NULL){
                // printf("cur's token is: %s\n", token);
                int tokenlen = strlen(token);                

                // Case insense
                if (para != NULL){
                    // printf("Here is Casse Insense!\n");

                    char tmp[tokenlen + 1];
                    strncpy(tmp, token, tokenlen); //Init tmp
    
                    //save lowercase to tmp
                    for (int i = 0; i < tokenlen; i++)
                        tmp[i] = tolower(token[i]);

                    // printf("tmp compare token:%s\n", tmp);
                    needle = strstr(tmp, old);

                    //if token has oldword need to replace
                    if(needle != NULL){
                        //create new str to replace old with new
                        int reslen = tokenlen + (newlen - oldlen) + 1;

                        char res[reslen];
                        int i = 0;
                        int res_i = 0;
                        char *tmp_ptr = tmp;

                        while(i < reslen){
                            for (tmp_ptr ; tmp_ptr < needle; tmp_ptr++){
                                res[res_i] = token[i];
                                res_i++;
                                i++;
                            }
                            for (int j = 0; j < newlen; j++){
                                res[res_i] = new[j];
                                res_i++;
                            }
                            for (int k = 0; k < oldlen; k++){
                                tmp_ptr++;
                                i++;
                            }
                            for (tmp_ptr; *tmp_ptr != '\0'; tmp_ptr++){
                                res[res_i] = token[i];
                                res_i++;
                                i++;
                            }
                        }
                        
                        res[reslen - 1] = '\0';
                        printf("%s\n", res);
                    }

                }
                
                //Case sense
                else{
                    needle = strstr(token, old);
                    //if token has oldword need to replace
                    if(needle != NULL){
                        //create new str to replace old with new
                        int reslen = tokenlen + (newlen - oldlen) + 1;

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
                        printf("%s\n", res);
                    }
                }
                
                
                token = strtok(NULL, article_delim);
            }
            
        }
    }
}

int check_parameter(char para[]){
    int flag = TRUE;
    if (para == NULL)
        return TRUE;
    else{
        if(strlen(para) != 2 || para[0] != '-' || para[1] != 'i')
            flag = FALSE;
    }
    return flag;
}

int check_str(char *str){
    int flag = TRUE;
    if(str == NULL)
        flag = FALSE;
    else{
        char tmp[strlen(str)];
        strncpy(tmp,str,strlen(str));
        for (int i = 0; i < strlen(str); i++)
        {
            if (isalnum(tmp[i]) == 0 && tmp[i] != '-'){
                // printf("checkstr:%c\n", tmp[i]);
                flag = FALSE;
                break;
            }
        }
    }
    return flag;
}