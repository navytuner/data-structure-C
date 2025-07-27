#ifndef __CIRCULAR_Q_H__
#define __CIRCULAR_Q_H__

#define QLEN 1000

struct circularq {
    int front;
    int rear;
    int arr[QLEN];
};

void q_init(struct circularq*);
int q_isempty(struct circularq*);
void q_push(struct circularq*, int data);
int q_pop(struct circularq*);
int q_top(struct circularq*);

#endif
