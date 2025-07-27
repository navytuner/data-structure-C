#include "linkedq.h"
#include <stdlib.h>

void q_init(struct linkedq *q){
    struct node *dummy = (struct node*)malloc(sizeof(struct node));
    dummy->next = 0;
    q->front = dummy;
    q->rear = dummy;
}

void q_push(struct linkedq *q, int data){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = 0;
    q->rear->next = newnode;
    q->rear = newnode;
}

int q_pop(struct linkedq *q){
    int data = q->front->next->data;
    struct node *rnode = q->front->next;
    if (rnode == q->rear){
        q->rear = q->front;
    }
    q->front->next = rnode->next;
    free(rnode);
    return data;
}

int q_front(struct linkedq *q){
    return q->front->next->data;
}

int q_isempty(struct linkedq *q){
    return q->front == q->rear;
}

