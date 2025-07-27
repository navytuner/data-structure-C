#include "deque.h"
#include <stdio.h>

int main(){
    struct deq dq;
    dq_init(&dq);

    for (int i = 1; i <= 5; i++){
        dq_push_back(&dq, i);
        printf("%d\n", dq_back(&dq));
    }
    for (int i = 1; i <= 5; i++){
        dq_push_front(&dq, i);
        printf("%d\n", dq_front(&dq));
    }

    printf("%d %d\n", dq_front(&dq), dq_back(&dq));
    while (!dq_isempty(&dq)){
        printf("%d\n", dq_pop_front(&dq));
    }
    return 0;
}