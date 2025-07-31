#include <stdio.h>

#define HLEN 100
int sz = 0;
int heap[HLEN]; // min heap

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void heap_push(int x){
    int idx = ++sz;
    heap[idx] = x;
    while (idx > 1){
        int pidx = (idx >> 1);
        if (heap[pidx] <= heap[idx]) break;
        swap(&heap[idx], &heap[pidx]);
        idx = pidx;
    }
}

int heap_top(void){
    return heap[1];
}

void heap_pop(void){
    int idx = 1;
    heap[1] = heap[sz--];
    while (2*idx <= sz){
        int lc = (idx << 1);
        int rc = (idx << 1) + 1;
        int minc = lc;
        if (rc <= sz && heap[rc] < heap[lc]) minc = rc;
        if (heap[idx] <= heap[minc]) break;
        swap(&heap[idx], &heap[minc]);
        idx = minc;
    }
}