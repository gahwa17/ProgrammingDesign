#include <string.h>
#include <stdio.h>

int read_line(); 

int main()
{
    char str[80] = " ";
    read_line(str, 100);
    char s[10] = " !?_\n\t,.";
    // char *token;

    char *old;
    char *new;
    char *para;

    // int cur = 0;
    /* get the first token */
    old = strtok(str, s);
    new = strtok(NULL, s);
    para = strtok(NULL, s);

    // /* walk through other tokens */
    // while(token != NULL) {
    //     // printf("%s\n", token );
    //     if(cur == 0)
    //         strcpy(old,token);
    //     else if(cur == 1)
    //         strcpy(new,token);
    //     else
    //         strcpy(para,token);
    //     token = strtok(NULL, s);
    //     cur++;
    // }
    printf("old:%s\n", old );
    printf("new:%s\n", new );
    printf("para:%s\n", para );

    return 0;
}

int read_line(char str[], int n)
{
    int ch, i = 0;
    while ((ch = getchar()) != '\n'){
        if (i < n)
        str[i++] = ch;
        str[i] = '\0'; /* terminates string */
    }
    return i; /* number of characters stored */
}