#include "stack.h"
#include <stdio.h>

int main(void){
    struct stack st;
    stack_init(&st);
    for (int i = 1; i <= 5; i++){
        stack_push(&st, i);
        printf("%d\n", stack_peek(&st));
    }

    printf("pop test\n");
    while (!stack_isempty(&st)){
        int val = stack_pop(&st);
        printf("%d\n", val);
    }

    return 0;

}