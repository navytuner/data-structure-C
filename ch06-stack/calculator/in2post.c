#include "in2post.h"
#include "stack.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#define MAX_LEN 100

int getprec(char op){
    switch(op){
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        case '(':
            return 0;
        default:
            return -1;
    }
}

void conv2post(char *dst, char *src){
    struct stack st;
    char *token;
    stack_init(&st);

    for (token = src; *token != 0; token++){
        if (isdigit(*token)){
            *(dst++) = *token;
            continue;
        }
        
        // *token == operator
        if (*token == '('){
            stack_push(&st, '(');
        }
        else if (*token == ')'){
            while (!stack_isempty(&st) && stack_peek(&st) != '('){
                *(dst++) = stack_pop(&st);
            }
            stack_pop(&st);
        }
        else if (*token == ' '){
            continue;
        }
        else {
            while (!stack_isempty(&st)){
                if (getprec(stack_peek(&st)) < getprec(*token))
                    break;
                *(dst++) = stack_pop(&st);
            }
            stack_push(&st, *token);
        }
    }
    while (!stack_isempty(&st)){
        *(dst++) = stack_pop(&st);
    }
}
