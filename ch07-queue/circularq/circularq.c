#include "circularq.h"
#include <stdio.h>

void q_init(struct circularq *q){
    q->front = 0;
    q->rear = 0;
}

int q_isempty(struct circularq *q){
    return q->front == q->rear;
}

void q_push(struct circularq *q, int data){
    q->rear = (q->rear + 1) % QLEN;
    q->arr[q->rear] = data;
}

int q_pop(struct circularq *q){
    q->front = (q->front + 1) % QLEN;
    return q->arr[q->front];
}

int q_top(struct circularq *q){
    return q->arr[q->front + 1];
}

