#include "linkedlist.h"
#include <stdio.h>

void show_list(struct linkedlist* list){
    int data;
    printf("Show list\n");
    if (list_first(list, &data)){
        printf("%d\n", data);
        while (list_next(list, &data)){
            printf("%d\n", data);
        }
    }
}

int comp(int a, int b){
    return a < b;
}

int main(void){
    struct linkedlist list;
    int data;
    list_init(&list);
    list_insert(&list, 1);
    list_insert(&list, 2);
    list_insert(&list, 3);
    list_insert(&list, 4);
    list_insert(&list, 5);

    printf("length of list: %d\n", list_len(&list));
    show_list(&list); 

    // delete 3
    if (list_first(&list, &data)){
        if (data == 3){
            list_remove(&list); 
        }
        else {
            while (list_next(&list, &data)){
                if (data == 3){
                    list_remove(&list);
                    break;
                }
            }
        }
    }

    printf("length of list: %d\n", list_len(&list));
    show_list(&list);
    printf("\n");

    printf("test sorted insert\n");
    list_setsort(&list, comp);
    list_insert(&list, 0);
    show_list(&list);
    return 0;
}