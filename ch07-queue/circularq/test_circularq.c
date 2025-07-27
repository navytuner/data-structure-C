#include "circularq.h"
#include <stdio.h>

int main(void){
    struct circularq q;
    q_init(&q);

    for (int i = 1; i <= 10; i++){
        q_push(&q, i);
    }

    while(!q_isempty(&q)){
        printf("%d\n", q_pop(&q));
    }
    return 0;
}