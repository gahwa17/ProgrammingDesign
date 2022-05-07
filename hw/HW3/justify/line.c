#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "line.h"
#define MAX_LINE_LEN 60
#define MAX_WORD_LEN 20
 
char line[MAX_LINE_LEN+1];

struct line{
  char word[MAX_WORD_LEN+1];
  struct line *next;
};

int line_len = 0;
int num_words = 0;
struct line *first = NULL;

void clear_line(void)
{
  //Free every node, not only the first pointer
  while (first){
    struct line *to_free = first;
    first = first->next;
    free(to_free);
  }

  //Init var
  line_len = 0;
  num_words = 0;
  

  /*Origin version

  line[0] = '\0';
  line_len = 0;
  num_words = 0;
  */
}

void add_word(const char *word)
{
  //Create new_word and add to the end of line list
  struct line *new_word = malloc(sizeof(struct line));
  strcpy(new_word->word, word);
  new_word->next = NULL;

  //First word,no need ' ' before it
  if(first == NULL){
    first = new_word;
  }
  else{
    //Find last node
    struct line *last =  first;
    while(last->next != NULL)
      last = last->next;
    last->next = new_word;  //Connect new_node to the end of line list

    //Note: except first word,all word need a ' ' before them, which take one space!!!
    line_len++;
  }

  line_len += strlen(word);
  num_words++;
  
  /*Origin version

  if (num_words > 0) {
    line[line_len] = ' ';
    line[line_len+1] = '\0';
    line_len++;
  }
  strcat(line, word);
  line_len += strlen(word);
  num_words++;
  */
  
}
 
int space_remaining(void)
{
  return MAX_LINE_LEN - line_len;
}

void write_line(void)
{
  int extra_spaces, spaces_to_insert;
  extra_spaces = MAX_LINE_LEN - line_len;
  
  // printf("line_len: %d\n",line_len);
  // printf("space_remaining: %d\n",space_remaining());

  
  struct line *to_print = first;

  while(to_print != NULL){
    //print word
    printf("%s",to_print->word);

    //Deal with extra_spaces
    if(num_words > 1){ //When it's not the last word
      spaces_to_insert = extra_spaces / (num_words - 1);
      for (int j = 1; j <= spaces_to_insert + 1; j++)
        putchar(' ');
      extra_spaces -= spaces_to_insert;
    }
    
    num_words--;
    to_print = to_print->next;
  }
  printf("\n");



  /* Origin version
  for (i = 0; i < line_len; i++) {
    if (line[i] != ' ')
      putchar(line[i]);
    else {
      spaces_to_insert = extra_spaces / (num_words - 1);
      for (j = 1; j <= spaces_to_insert + 1; j++)
        putchar(' ');
      extra_spaces -= spaces_to_insert;
      num_words--;
    }
  }
  putchar('\n');
  */
}

//When it comes to the last word, directly print the left words in one line
//No need to deal with extra space
void flush_line(void)
{
  if (line_len > 0){
    struct line *to_print = first;
    while(to_print){
      printf("%s ",to_print->word);
      to_print = to_print->next;
    }
  }
  printf("\n");
  /* Origin version
  if (line_len > 0)
    puts(line);
  */
}
