#include <stdio.h>
#include <stdlib.h>
#include "arraylist.h"
#include "point.h"

int main(void){
    struct arraylist list;
    struct point *point;
    list_init(&list);

    point = (struct point*)malloc(sizeof(struct point));
    set_point(point, 2, 1);
    list_insert(&list, point);    

    point = (struct point*)malloc(sizeof(struct point));
    set_point(point, 2, 2);
    list_insert(&list, point);    

    point = (struct point*)malloc(sizeof(struct point));
    set_point(point, 3, 1);
    list_insert(&list, point);    

    point = (struct point*)malloc(sizeof(struct point));
    set_point(point, 3, 2);
    list_insert(&list, point);   

    printf("length of list: %d\n", list_count(&list));

    // Show points
    if (list_first(&list, &point)){
        show_point(point);
        while (list_next(&list, &point)){
            show_point(point);
        }
    }
    printf("\n");
   
    return 0;
}