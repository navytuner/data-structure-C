#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* bintree_make(void);
int bintree_getdata(struct node *node);
void bintree_setdata(struct node *node, int data);
struct node* bintree_left(struct node *node);
struct node* bintree_right(struct node *node);
void bintree_make_left(struct node *main, struct node *sub);
void bintree_make_right(struct node *main, struct node *sub);

void inorder_traverse(struct node *tree);
void preorder_traverse(struct node *tree);
void postorder_traverse(struct node *tree);

#endif