#include "dlinkedlist.h"
#include <stdlib.h>

void list_init(struct dlinkedlist *list){
    struct node *dummy = (struct node*)malloc(sizeof(struct node));
    dummy->next = 0;
    dummy->prev = 0;
    list->len = 0;
    list->head = dummy;
    list->cur = dummy;
}

void list_insert(struct dlinkedlist *list, int data){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = list->head->next;
    newnode->prev = list->head;
    if (list->head->next)
        list->head->next->prev = newnode;
    list->head->next = newnode;
    list->len += 1;
}

int list_first(struct dlinkedlist *list, int* data){
    if (list->head->next == NULL)
        return 0;
    list->cur = list->head->next;
    *data = list->cur->data;
    return 1;
}

int list_next(struct dlinkedlist *list, int* data){
    if (list->cur->next == NULL)
        return 0;
    list->cur = list->cur->next;
    *data = list->cur->data;
    return 1;
}

int list_prev(struct dlinkedlist *list, int* data){
    if (list->cur->prev == list->head)
        return 0;
    list->cur = list->cur->prev;
    *data = list->cur->data;
    return 1;
}

int list_remove(struct dlinkedlist *list){
    int data = list->cur->data;
    struct node *target = list->cur;
    list->cur = list->cur->prev;
    target->prev->next = target->next;
    if (target->next)
        target->next->prev = target->prev;
    free(target);
    list->len -= 1;
    return data;
}

int list_len(struct dlinkedlist *list){
    return list->len;
}
