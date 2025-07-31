#include "bst.h"
#include <stdio.h>

int main(){
    struct node *root = bst_newnode(50);
    bst_insert(root, 30);
    bst_insert(root, 20);
    bst_insert(root, 40);
    bst_insert(root, 70);
    bst_insert(root, 60);
    bst_insert(root, 80);

    bst_display(root);

    // search
    struct node *snode;
    snode = bst_search(root, 40);
    printf("search successfully: %d\n", snode->key);

    // deletion
    bst_delete(root, 40);
    bst_display(root);
    return 0;
}