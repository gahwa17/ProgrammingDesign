#include <stdio.h>
#include <string.h>


int main()
{
   char str[200] = "He is our new TA called Bo-Zheng, Chen.";
   char old[100] = "he";
   char new[100] = "it";

   int oldlen = strlen(old);
   int newlen = strlen(new);

   char skip[10] = " !?_\n\t,.";
   char *token;
   char *needle;
   token = strtok(str, skip);
   while(token != NULL){
      int cnt = 0;
      int tokenlen = strlen(token);

      // printf("%s %d\n", token,tokenlen);

      needle = strstr(token, old);
      if(needle != NULL){
         // printf("needle: %s \n", needle);

         //count how many oldword exist in one token 
         for (int i = 0; token[i] != '\0';i++){
            if(strstr(&token[i],old)==&token[i]){
               cnt++;
               i = i + oldlen;
            }
         }

         //create new str to replace old with new
         int reslen = tokenlen + (newlen - oldlen) * cnt + 1;

         char res[reslen];
         int i = 0;
         char *ptr = token;
         /*Wrong Think
         while(*token){
            if(strstr(ptr,old) == ptr){
               strcpy(&res[i], new);
               printf("Before ptr is:%c\n",*ptr);
               ptr += oldlen;
               printf("cur ptr is:%c\n",*ptr);
               i += newlen;
            }
            else{
               res[i] = *ptr;
               i++;
               ptr++;
            }
         }
         */
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
   return(0);
}
