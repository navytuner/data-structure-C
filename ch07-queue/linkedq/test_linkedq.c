#include "linkedq.h"
#include <stdio.h>

int main(void){
    struct linkedq q;
    q_init(&q);
    for (int i = 1; i <= 6; i++){
        q_push(&q, i);
    }

    while (!q_isempty(&q)){
        printf("%d\n", q_pop(&q));
    }

    for (int i = 2; i <= 10; i += 2){
        q_push(&q, i);
    }    
    while (!q_isempty(&q)){
        printf("%d\n", q_pop(&q));
    }


    return 0;
}