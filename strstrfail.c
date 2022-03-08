#include <stdio.h>
#include <string.h>


int main()
{
    const char haystack[20] = "He";
    const char needle[10] = "He";
    char *ret;

    ret = strstr(haystack, needle);
    char *ptr = ret;
    printf("The substring is: %s\n", ret);
    printf("The ptr is: %c\n", *ptr);

    return(0);
}