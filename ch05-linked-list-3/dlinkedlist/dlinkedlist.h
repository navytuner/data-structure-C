#ifndef __DLINKED_LIST_H__
#define __DLINKED_LIST_H__

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct dlinkedlist {
    struct node *head; // indicate dummy
    struct node *cur;
    int len;
};

void list_init(struct dlinkedlist*);
void list_insert(struct dlinkedlist*, int);
int list_first(struct dlinkedlist*, int*);
int list_next(struct dlinkedlist*, int*);
int list_prev(struct dlinkedlist*, int*);
int list_remove(struct dlinkedlist*);
int list_len(struct dlinkedlist*);

#endif