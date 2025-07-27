#include "binarytree.h"
#include <stdlib.h>
#include <stdio.h>

struct node* bintree_make(void){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->left = 0;
    newnode->right = 0;
    return newnode;
}

int bintree_getdata(struct node *node){
    return node->data;
}

void bintree_setdata(struct node *node, int data){
    node->data = data;
}

struct node* bintree_left(struct node *node){
    return node->left;
}

struct node* bintree_right(struct node *node){
    return node->right;
}

void bintree_make_left(struct node *main, struct node *sub){
    if (main->left)
        free(main->left);
    main->left = sub;
}

void bintree_make_right(struct node *main, struct node *sub){
    if (main->right)
        free(main->right);
    main->right = sub;
}

void inorder_traverse(struct node *tree){
    if (tree == 0) return;
    inorder_traverse(tree->left);
    printf("%d\n", tree->data);
    inorder_traverse(tree->right);
}

void preorder_traverse(struct node *tree){
    if (tree == 0) return;
    printf("%d\n", tree->data);
    preorder_traverse(tree->left);
    preorder_traverse(tree->right);
}

void postorder_traverse(struct node *tree){
    if (tree == 0) return;
    postorder_traverse(tree->left);
    postorder_traverse(tree->right);
    printf("%d\n", tree->data);
}
