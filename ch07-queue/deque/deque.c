#include "deque.h"
#include <stdlib.h>

void dq_init(struct deq *dq){
    dq->front = 0;
    dq->rear = 0;
}

void dq_push_front(struct deq *dq, int data){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->prev = 0;
    if (dq_isempty(dq)){
        newnode->next = 0;
        dq->front = newnode;
        dq->rear = newnode;
    }
    else {
        newnode->next = dq->front;
        dq->front->prev = newnode;
        dq->front = newnode;
    }

    // if use dummy, there is no need to check isempty
    // struct node *tmp = dq->front->next;
    // tmp->prev = newnode;
    // dp->front->next = newnode;
    // newnode->prev = dq->front;
    // newnode->next = tmp;
}

void dq_push_back(struct deq *dq, int data){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = 0;
    if (dq_isempty(dq)){
        newnode->prev = 0;
        dq->front = newnode;
        dq->rear = newnode;
    }
    else {
        newnode->prev = dq->rear;
        dq->rear->next = newnode;
        dq->rear = newnode;
    }
}

int dq_pop_front(struct deq *dq){
    struct node *target = dq->front;
    int rdata = target->data;
    if (dq->front == dq->rear){
        dq->front = 0;
        dq->rear = 0;
    }
    else {
        target->next->prev = 0;
        dq->front = target->next;
    }
    free(target);
    return rdata;
}

int dq_pop_back(struct deq *dq){
    struct node *target = dq->rear;
    int rdata = target->data;
    if (dq->front == dq->rear){
        dq->front = 0;
        dq->rear = 0;
    }
    else {
        target->prev->next = 0;
        dq->rear = target->prev;
    }
    free(target);
    return rdata;
}

int dq_front(struct deq *dq){
    return dq->front->data;
}

int dq_back(struct deq *dq){
    return dq->rear->data;
}

int dq_isempty(struct deq *dq){
    return (dq->front == 0 && dq->rear == 0);
}

