#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

void stack_init(struct stack* stack){
    stack->head = 0;
}

int stack_isempty(struct stack* stack){
    return (stack->head)? 0 : 1;
}

void stack_push(struct stack* stack, char data){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = stack->head;
    stack->head = newnode;
}

char stack_peek(struct stack* stack){
    if (stack->head == 0) exit(-1);
    return stack->head->data;
}

char stack_pop(struct stack* stack){
    int data = stack->head->data;
    struct node *top = stack->head;
    stack->head = top->next;
    free(top);
    return data;
}

