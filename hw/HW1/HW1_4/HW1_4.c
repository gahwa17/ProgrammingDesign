#include <stdio.h>


#define MAX_WORDS 100000

void read_word();
int read_char();

/* Count how many times a word appears in the sentence */
int main(void){
    char sentnece[MAX_WORDS];
    char word[MAX_WORDS];

    char *sentnece_ptr = sentnece;
    char *word_ptr = word;


    int cnt = 0;

    //Init sentence
    for(int i = 0 ; i < MAX_WORDS ; i++)
        sentnece[i] = '\0';

    //Read sentence and word
    fgets(sentnece,MAX_WORDS,stdin);
    scanf("%s",word);

    //Deal with '\r'
    for(char *sentnece_deal = &sentnece[0] ; *sentnece_deal !='\0' ; sentnece_deal++){
        char ch = *sentnece_deal;
        if(ch == '\r')
            *sentnece_deal = '\n';
    }
    for(char *word_deal = &word[0] ; *word_deal != '\0'; word_deal++){
        char ch = *word_deal;
        if(ch == '\r')
            *word_deal = '\n';
    }

    //Debug
    // printf("sentnece: %s",sentnece);
    // printf("word: %s\n",word);

    //strlen
    int word_len = 0;
    for(char *word_ptr = &word[0] ; *word_ptr != '\0'; word_ptr++)
        word_len++;
    // printf("word_len: %d",word_len);

    char ch;
    if(sentnece_ptr == NULL || word_ptr == NULL)
        printf("%d",cnt);
    else{
        for(char *sentnece_ptr = &sentnece[0] ; *sentnece_ptr !='\n' ; sentnece_ptr++){
            ch = *sentnece_ptr;
            int flag = 1;
            for(int word_index = 0 ; word_index < word_len ; word_index++){
                if(ch == word[word_index]){
                    // printf("ch[%c] = word[%c]\n", ch, word[word_index]);
                    sentnece_ptr++;
                    ch = *sentnece_ptr;
                    if(word_index == word_len - 1)
                        sentnece_ptr--;
                }
                else{
                    // printf("ch[%c] != word[%c]\n", ch, word[word_index]);
                    flag = 0;
                    break;
                }
            }


            char cur_next = *(sentnece_ptr + 1);
            int cur_next_ascii = cur_next;

            if( cur_next != ' ' && cur_next_ascii > 29 && cur_next != ','){
                // printf("[next: %c]",cur_next);
                // printf("[ascii: %d]\n",cur_next_ascii);
                flag = 0;
            }

            char cur_prev = *(sentnece_ptr - word_len);
            int cur_prev_ascii = cur_prev;

            if( cur_prev != ' ' && cur_prev_ascii > 29 && cur_prev != ','){
                // printf("[prev: %c]",cur_prev);
                // printf("[ascii: %d]\n",cur_prev_ascii);
                flag = 0;
            }

            // printf("cur flag: %d\n",flag);

            if(flag == 1)
                cnt++;
        }
    }
    printf("%d",cnt);
}
