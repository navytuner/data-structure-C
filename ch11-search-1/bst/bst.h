#ifndef __BST_H__
#define __BST_H__

struct node {
    int key;
    struct node *lc;
    struct node *rc;
};

struct node* bst_newnode(int key);
void bst_insert(struct node *root, int key);
struct node* bst_search(struct node *root, int key);
void bst_display(struct node *root);
void bst_freeall(struct node *root);
struct node* bst_delete(struct node *root, int key);

#endif