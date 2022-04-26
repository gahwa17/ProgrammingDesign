#ifndef myDS_H
#define myDS_H

typedef int BOOL;

//stack
void _stack_push(int value);
void _stack_pop();
int _stack_top();

//queue
void _queue_push(int value);
void _queue_pop();
int _queue_front();

//check state
BOOL _queue_empty();
BOOL _stack_empty();

#endif