#include <stdio.h>
#include "exptree.h"
#include <ctype.h>
#include <stdlib.h>

#define STLEN 100

struct node* st[STLEN];
static int tail = -1;

static void push(struct node *node){
    st[++tail] = node;
}
static struct node* pop(void){
    return st[tail--];
}
// static int isempty(void){
//     return (tail == -1);
// }

struct node* exptree_make(char *exp){
    char *token;
    for (token = exp; *token != 0; token++){
        if (isdigit(*token)){
            struct node *operand = (struct node*)malloc(sizeof(struct node));
            operand->data = *token;
            operand->lc = 0;
            operand->rc = 0;
            push(operand);
        }
        else {
            struct node *operator = (struct node*)malloc(sizeof(struct node));
            operator->data = *token;
            operator->rc = pop();
            operator->lc = pop();
            push(operator); 
        }
    }
    return pop();
}

int exptree_cal(struct node *tree){
    if (isdigit(tree->data))
        return tree->data - '0';
    
    switch(tree->data){
        case '+':
            return exptree_cal(tree->lc) + exptree_cal(tree->rc);
        case '-':
            return exptree_cal(tree->lc) - exptree_cal(tree->rc);
        case '*':
            return exptree_cal(tree->lc) * exptree_cal(tree->rc);
        case '/':
            return exptree_cal(tree->lc) / exptree_cal(tree->rc);
    }
    return -1;
}

void display_prefix(struct node *tree){
    if (tree == 0) return;
    printf("%c ", tree->data);
    display_prefix(tree->lc);
    display_prefix(tree->rc);
}

void display_inorder(struct node *tree){
    if (tree == 0) return;
    display_inorder(tree->lc);
    printf("%c", tree->data);
    display_inorder(tree->rc);
}

void display_postfix(struct node *tree){
    if (tree == 0) return;
    display_postfix(tree->lc);
    display_postfix(tree->rc);
    printf("%c ", tree->data);
}
