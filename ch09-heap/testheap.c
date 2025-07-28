#include "heap.h"
int main(void){
    struct heap heap;
    heap_init(&heap);
    heap_push(&heap, 5, '5');
    heap_push(&heap, 4, '4');
    heap_push(&heap, 3, '3');
    heap_push(&heap, 2, '2');
    heap_push(&heap, 1, '1');
    heap_display(&heap);

    heap_pop(&heap);
    heap_display(&heap);
    heap_pop(&heap);
    heap_display(&heap);

    return 0;
}