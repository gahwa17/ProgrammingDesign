#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0
#define MAX_PATN 100
#define MAX_ARC 4095

int check_parameter(); // check whether parameter is valid

int main(void){
    char arc[MAX_ARC];
    char *old;
    char *new;
    char *para;

    fprintf(stderr, "Enter pattern, replacement, and at most one parameter: \n");
    char pattern[MAX_PATN];
    char delim[10] = " !?_\n\t,.";

    //Pattern
    fgets(pattern, MAX_PATN, stdin);

    old = strtok(pattern, delim);
    new = strtok(NULL, delim);
    para = strtok(NULL, delim);


    //check parameter
    if(old == NULL)
        fprintf(stderr, "The input format: string1 string2 [parameter]");
    else if(strtok(NULL, delim)!= NULL || check_parameter(para) == FALSE)
        fprintf(stderr, "The input format: string1 string2 [parameter]");
    else{

        int oldlen = strlen(old);
        int newlen = strlen(new);

        // printf("oldlen: %d\n", oldlen);
        // printf("newlen: %d\n", newlen);


        // printf("old:%s\n", old);
        // printf("new:%s\n", new);
        // printf("para:%s\n", para);


        fprintf(stderr, "Enter the article: \n");

        while(fgets(arc,MAX_ARC,stdin) != NULL){
            //Case insensitive : old and arc tolowercase
            if(para != NULL){
                int i = 0;
                while (old[i]){
                    old[i] = tolower(old[i]);
                    i++;
                }
                // printf("new old:%s\n", old);
            }
            
            int arclen = strlen(arc);
            arc[arclen - 1] = '\0';

            // printf("cur's arc: %s\n", arc);

            //filter special char
            char article_delim[MAX_ARC];
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

                //copy token to tmptoken to deal with case insense
                char tmp[tokenlen];
                strncpy(tmp, token,tokenlen); //Init tmp

                // Case insense
                if (para != NULL){
                    for (int i = 0; i < tokenlen; i++){
                        tmp[i] = tolower(token[i]);
                    }
                    // printf("tmp compare token:%s\n", tmp);
                    needle = strstr(tmp, old);

                    //if token has oldword need to replace
                    if(needle != NULL){
                        //create new str to replace old with new
                        int reslen = tokenlen + (newlen - oldlen) + 1;

                        char res[reslen];
                        int i = 0;

                        while(i < reslen){
                            char *tmp_ptr = tmp;
                            for (tmp_ptr ; tmp_ptr < needle; tmp_ptr++){
                                res[i] = token[i];
                                i++;
                            }
                            for (int j = 0; j < newlen; j++){
                                res[i] = new[j];
                                i++;
                            }

                            for (int k = 0; k < oldlen; k++)
                                tmp_ptr++;
                                
                            for (tmp_ptr ; *tmp_ptr!='\0' ; tmp_ptr++){
                                res[i] = token[i];
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