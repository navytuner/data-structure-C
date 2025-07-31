#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

struct node* bst_newnode(int key){
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->key = key;
    node->lc = 0;
    node->rc = 0;
    return node;    
}

// assume there is no duplicate keys
void bst_insert(struct node *root, int key){
    struct node *node = bst_newnode(key);
    struct node *cmp = root;
    while (1){
        if (key < cmp->key){
            if (cmp->lc == 0){
                cmp->lc = node;
                return;
            }
            cmp = cmp->lc;
        }
        else {
            if (cmp->rc == 0){
                cmp->rc = node;
                return;
            }
            cmp = cmp->rc;
        }
    }
}

struct node* bst_search(struct node *root, int key){
    if (!root) return NULL;
    if (root->key == key) return root;
    else if (key < root->key) return bst_search(root->lc, key);
    else return bst_search(root->rc, key);
}

void bst_display(struct node *root){
    // inorder traversal
    if (root == 0) return;
    bst_display(root->lc);
    printf("%d\n", root->key);
    bst_display(root->rc);
}

void bst_freeall(struct node *root){
    if (root == 0) return;
    bst_freeall(root->lc);
    bst_freeall(root->rc);
    free(root);
}

struct node* bst_delete(struct node *root, int key){
    if (!root) return NULL; 
    if (key < root->key) root->lc = bst_delete(root->lc, key);
    else if (key > root->key) root->rc = bst_delete(root->rc, key);
    else {
        // target node
        // 1 or no child
        if (!root->lc){
            struct node *tmp = root->rc;
            free(root);
            return tmp;
        }
        else if (!root->rc){
            struct node *tmp = root->lc;
            free(root);
            return tmp;
        }

        // 2 children
        struct node *tmp = root->rc;
        while (tmp->lc){
            tmp = tmp->lc;
        }
        root->key = tmp->key;
        root->rc = bst_delete(root->rc, tmp->key); 
    }
    return root;
}
