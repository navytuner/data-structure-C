#include <stdio.h>
#include <stdlib.h>
#include "cirlist.h"

void list_init(struct cirlist *list){
    list->tail = 0;
    list->cur = 0;
    list->before = 0;
    list->len = 0;
}

void list_insert(struct cirlist *list, int data){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    if (list->tail){
        newnode->next = list->tail->next;
        list->tail->next = newnode;
        list->tail = newnode;
    }
    else {
        list->tail = newnode;
        newnode->next = newnode;
    }
    list->len += 1;
}

void list_insert_head(struct cirlist *list, int data){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    if (list->tail){
        newnode->next = list->tail->next;
        list->tail->next = newnode;
    }
    else {
        list->tail = newnode;
        newnode->next = newnode;
    }
    list->len += 1;
}

int list_first(struct cirlist *list, int *pdata){
    if (list->tail){
        list->cur = list->tail->next;
        list->before = list->tail;
        *pdata = list->cur->data;
        return 1;
    }
    return 0;
}

int list_next(struct cirlist *list, int *pdata){
    if (list->cur->next){
        list->before = list->cur;
        list->cur = list->cur->next;
        *pdata = list->cur->data;
        return 1;
    }
    return 0;
}

int list_remove(struct cirlist *list){
    int data = list->cur->data;

    // only 1 element
    if (list->cur == list->before){
        free(list->cur);
        list->cur = 0;
        list->before = 0;
        list->tail = 0;
        list->len = 0;
        return data;
    }

    if (list->cur == list->tail)
        list->tail = list->before;
    list->before->next = list->cur->next;
    free(list->cur);
    list->cur = list->before;
    list->len -= 1;
    return data;
}

int list_len(struct cirlist *list){
    return list->len;
}

