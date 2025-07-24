#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

void list_init(struct linkedlist *list){
    struct node *dummy = (struct node*)malloc(sizeof(struct node));
    dummy->next = 0;

    list->head = dummy;
    list->cur = dummy;
    list->before = 0;
    list->len = 0;
    list->comp = 0;
}

void list_insert(struct linkedlist *list, int data){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;

    if (list->comp == 0 || list->head->next == 0){
        newnode->next = list->head->next;
        list->head->next = newnode;
    }
    else {
        struct node *tmp = list->head;
        while (tmp->next && list->comp(data, tmp->next->data)){
            tmp = tmp->next;
        } 
        newnode->next = tmp->next;
        tmp->next = newnode;
    }
    list->len += 1;
}

int list_first(struct linkedlist *list, int *pdata){
    list->cur = list->head->next;
    list->before = list->head;
    if (list->cur == 0) return 0;
    *pdata = list->cur->data;
    return 1;
}

int list_next(struct linkedlist *list, int *pdata){
    if (list->cur->next == 0) return 0;
    list->before = list->cur;
    list->cur = list->cur->next;
    *pdata = list->cur->data;
    return 1;
}

int list_remove(struct linkedlist *list){
    if (list->cur == list->head) return -1;
    int rmdata = list->cur->data;
    list->before->next = list->cur->next;
    free(list->cur);
    list->cur = list->before;
    list->len -= 1;
    return rmdata; 
}

int list_len(struct linkedlist *list){
    return list->len;
}

void list_setsort(struct linkedlist *list, int (*comp)(int, int)){
    list->comp = comp;
}

