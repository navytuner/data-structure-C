#ifndef __DEQ_H__
#define __DEQ_H__

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct deq {
    struct node *front;
    struct node *rear;
};

void dq_init(struct deq *dq);
void dq_push_front(struct deq *dq, int data);
void dq_push_back(struct deq *dq, int data);
int dq_pop_front(struct deq *dq);
int dq_pop_back(struct deq *dq);
int dq_front(struct deq *dq);
int dq_back(struct deq *dq);
int dq_isempty(struct deq *dq);

#endif