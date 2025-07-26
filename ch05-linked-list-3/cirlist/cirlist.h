#ifndef __CIRLIST_H__
#define __CIRLIST_H__

struct node {
    int data;
    struct node *next;
};

struct cirlist {
    struct node *tail;
    struct node *cur;
    struct node *before;
    int len;
};

void list_init(struct cirlist*);
void list_insert(struct cirlist*, int); // insert node to tail
void list_insert_head(struct cirlist*, int);
int list_first(struct cirlist*, int*);
int list_next(struct cirlist*, int*);
int list_remove(struct cirlist*);
int list_len(struct cirlist*);

#endif
