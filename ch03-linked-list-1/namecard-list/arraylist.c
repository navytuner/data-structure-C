#include "arraylist.h"

void list_init(struct arraylist *list){
   list->len = 0;
   list->cur = 0; 
}

void list_insert(struct arraylist *list, LData data){
    list->arr[(list->len)++] = data;
}

int list_first(struct arraylist *list, LData* pdata){
    if (list->len == 0) return 0;
    list->cur = 0;
    *pdata = list->arr[0];
    return 1;
}

int list_next(struct arraylist *list, LData* pdata){
   if (list->cur >= list->len-1) return 0;
   list->cur += 1;
   *pdata = list->arr[list->cur];
   return 1; 
}

LData list_remove(struct arraylist *list){
    LData data = list->arr[list->cur];
    for (int i = list->cur; i < list->len+1; i++){
        list->arr[i] = list->arr[i+1];
    }
    (list->len)--;
    (list->cur)--;
    return data;
}

int list_count(struct arraylist *list){
    return list->len;
}
