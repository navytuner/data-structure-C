#ifndef __STACK_H__
#define __STACK_H__

struct node {
    int data;
    struct node *next;
};

struct stack {
    struct node *head;
};

void stack_init(struct stack*);
int stack_isempty(struct stack*);
void stack_push(struct stack*, int);
int stack_peek(struct stack*);
int stack_pop(struct stack*);

#endif