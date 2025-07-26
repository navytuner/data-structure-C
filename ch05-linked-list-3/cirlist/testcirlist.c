#include "cirlist.h"
#include <stdio.h>

void show_list(struct cirlist *list, int num){
    int data;
    if (list_first(list, &data)){
        printf("1. %d\n", data);
        for (int i = 0; i < num-1; i++){
            if (list_next(list, &data)){
                printf("%d. %d\n", 2+i, data);
            }
        } 
    }
}

int main(void){
    struct cirlist list;
    list_init(&list);
    list_insert(&list, 1);
    list_insert(&list, 2);
    list_insert(&list, 3);
    list_insert(&list, 4);
    list_insert(&list, 5);

    int len = list_len(&list);
    int data;
    list_first(&list, &data);
    if (data % 2 == 0) list_remove(&list);
    for (int i = 0; i < len-1; i++){
        list_next(&list, &data);
        if (data % 2 == 0) list_remove(&list);
    }
    show_list(&list, 5);
    return 0;
}