#include <stdio.h>
#include "dlinkedlist.h"

void show_list(struct dlinkedlist *list){
    int data;
    int len = list->len;
    list_first(list, &data);
    printf("1. %d\n", data);
    for (int i = 0; i < len-1; i++){
        list_next(list, &data);
        printf("%d. %d\n", 2+i, data);
    }
}

int main(void){
    struct dlinkedlist list;
    list_init(&list);
    for (int i = 1; i <= 8; i++){
        list_insert(&list, i);
    }
    show_list(&list);

    int data;
    list_first(&list, &data);
    if (data % 2 == 0)
        list_remove(&list);
    
    while (list_next(&list, &data)){
        if (data % 2 == 0)
            list_remove(&list);
    }
    show_list(&list);
    return 0;
}
