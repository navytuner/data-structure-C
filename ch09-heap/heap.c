#include "heap.h"
#include <stdio.h>

void swap(struct hent *a, struct hent *b){
    struct hent tmp = {a->pri, a->data};
    *a = *b;
    *b = tmp;
}

void heap_init(struct heap *hp){
    hp->sz = 0;
}

void heap_push(struct heap *hp, int pri, char data){
    int idx = ++(hp->sz);
    hp->arr[idx] = (struct hent){pri, data};
    while (idx > 1){
        int pidx = idx / 2;
        if (hp->arr[idx].pri < hp->arr[pidx].pri){
            swap(&(hp->arr[idx]), &(hp->arr[pidx]));
            idx = pidx;
        }
    }
}

char heap_pop(struct heap *hp){
    char res = hp->arr[1].data;
    int idx = 1;
    hp->arr[1] = hp->arr[(hp->sz)--];
    while (2*idx <= hp->sz){
        int lc = (idx << 1);
        int rc = (idx << 1) + 1;
        int minc = lc;
        if (rc <= hp->sz && hp->arr[rc].pri < hp->arr[lc].pri)
            minc = rc;
        if (hp->arr[idx].pri <= hp->arr[minc].pri)
            break;
        swap(&(hp->arr[idx]), &(hp->arr[minc]));
        idx = minc;
    }
    return res;
}

char heap_top(struct heap *hp){
    return hp->arr[1].data;
}

void heap_display(struct heap *hp){
    for (int i = 1; i <= hp->sz; i++){
        printf("%c ", hp->arr[i].data);
    }
    printf("\n");
}
