#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

struct node {
    int data;
    struct node *next;
};

struct linkedlist {
    struct node *head;
    struct node *cur;
    struct node *before;
    int len;
    int (*comp)(int, int); 
}; 

void list_init(struct linkedlist*);
void list_insert(struct linkedlist*, int);
int list_first(struct linkedlist*, int*);
int list_next(struct linkedlist*, int*);
int list_remove(struct linkedlist*);
int list_len(struct linkedlist*);
void list_setsort(struct linkedlist*, int (*)(int, int));

#endif