#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__
#include "point.h"

#define LIST_LEN 100
typedef struct point* LData;

struct arraylist {
    LData arr[LIST_LEN]; 
    int len;
    int cur;
};

void list_init(struct arraylist*);
void list_insert(struct arraylist*, LData);
int list_first(struct arraylist*, LData*);
int list_next(struct arraylist*, LData*);
LData list_remove(struct arraylist*);
int list_count(struct arraylist*);

#endif