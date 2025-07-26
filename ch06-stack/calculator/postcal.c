#include "postcal.h"
#include "stack.h"
#include <string.h>
#include <ctype.h>

int postcal(char *exp){
    struct stack st;
    stack_init(&st);

    char *token;
    for (token = exp; *token != 0; token++){
        if (isdigit(*token)){
            stack_push(&st, *token);
        }
        else {
            int a = stack_pop(&st) - '0';
            int b = stack_pop(&st) - '0';
            char op = *token;
            int res;
            switch(op){
                case '+':
                    res = a + b;
                    break;
                case '-':
                    res = a - b;
                    break;
                case '*':
                    res = a * b;
                    break;
                case '/':
                    res = a / b;
                    break;
            }
            stack_push(&st, res + '0');
        }
    }
    return stack_pop(&st) - '0';
}