#ifndef __EXPTREE_H__
#define __EXPTREE_H__

struct node {
    char data;
    struct node *lc;
    struct node *rc;
};

struct node* exptree_make(char *exp);
int exptree_cal(struct node*);

void display_prefix(struct node*);
void display_inorder(struct node*);
void display_postfix(struct node*);

#endif