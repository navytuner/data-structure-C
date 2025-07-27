#include "in2post.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define STLEN 100

static char opstack[STLEN];
static int tail = -1;

static char top(void){
    return opstack[tail];
}
static void push(char op){
    opstack[++tail] = op;
}
static char pop(void){
    return opstack[tail--];
}
static int isempty(void){
    return (tail == -1);
}
static int getprec(char op){
    switch(op){
        case '(':
            return 0;
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
    }
    return -1;
}

void in2post(char *dst, char *src){
    char *token;
    for (token = src; *token != 0; token++){
        if (isdigit(*token)){
            *(dst++) = *token;
        } 
        else {
            if (*token == '('){
                push(*token);
            }
            else if (*token == ')'){
                while (!isempty() && top() != '('){
                    *(dst++) = pop();
                }
                pop();
            }
            else {
                while (!isempty() && getprec(top()) >= getprec(*token)){
                    *(dst++) = pop();
                }
                push(*token);
            }
        }
    }
    while (!isempty()){
        *(dst++) = pop();
    }
    *dst = 0;
}