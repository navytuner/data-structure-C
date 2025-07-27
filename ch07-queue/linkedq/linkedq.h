#ifndef __LINKEDQ_H__
#define __LINKEDQ_H__

struct node {
    int data;
    struct node *next;
};

struct linkedq {
    struct node *front;
    struct node *rear;
};

void q_init(struct linkedq *);
void q_push(struct linkedq *, int);
int q_pop(struct linkedq *);
int q_front(struct linkedq *);
int q_isempty(struct linkedq *);

#endif