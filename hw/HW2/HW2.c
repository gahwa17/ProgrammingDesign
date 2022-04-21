#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LENGTH 50

struct course{
    char name[NAME_LENGTH];
    struct course *next;
    struct course *prior;
};

struct id{
    int id;
    int next_id;
    int prior_id;
    struct course *course_ptr;
};

struct course *find_course(struct id mapper[],int id,int mappersize);

int main(void){

    int course_num = 0;
    scanf("%d", &course_num);
    struct id mapper[course_num];

    //Create id mapper and point to a course node
    for(int i = 0 ; i < course_num ; i++){
        struct course *new_course = malloc(sizeof(struct course));
        mapper[i].course_ptr = new_course;

        scanf("%d %d %d %s",&mapper[i].id, &mapper[i].next_id, &mapper[i].prior_id, new_course->name);
    }

    //Link the next & prior node according to mapper
    for(int i = 0 ; i < course_num ; i++){
        int next_id = mapper[i].next_id;
        int prior_id = mapper[i].prior_id;

        (mapper[i].course_ptr) -> next = find_course(mapper,next_id,course_num);
        (mapper[i].course_ptr) -> prior = find_course(mapper,prior_id,course_num);
    }

    //Keep the first pointer of course
    struct course *first = mapper[0].course_ptr;
    

    //Remove the link between mapper and course (Not free!!!)
    for(int i = 0 ; i < course_num ; i++){
        mapper[i].course_ptr = NULL;
    }

    char choice;
    printf("Current Course: %s\n",first->name);

    while(choice != 'q'){
        printf("[n] Next course. [p] Prior course [q] Quit:");
        scanf(" %c",&choice);
        if(choice == 'n'){
            if(first -> next == NULL){
                printf("There is no next course.\n");
                printf("Current Course: %s\n",first->name);
            }
            else{
                first = first -> next;
                printf("Current Course: %s\n",first->name);
            }
        }
        if(choice == 'p'){
            if(first -> prior == NULL){
                printf("There is no previous course.\n");
                printf("Current Course: %s\n",first->name);
            }
            else{
                first = first -> prior;
                printf("Current Course: %s\n",first->name);
            }
        }
    }

    return 0;
}


//Find course pointer by id
struct course *find_course(struct id mapper[],int id,int mappersize){
    for(int i = 0; i < mappersize ; i++){
        if(mapper[i].id == id){
            return mapper[i].course_ptr;
        }
    }

    //Can't find correspond course
    return NULL;
}