#include "binarytree.h"
#include <stdio.h>

int main(){
    struct node *a = bintree_make();
    struct node *b = bintree_make();
    struct node *c = bintree_make();
    struct node *d = bintree_make();
    struct node *e = bintree_make();
    struct node *f = bintree_make();
    
    bintree_setdata(a, 1);
    bintree_setdata(b, 2);
    bintree_setdata(c, 3);
    bintree_setdata(d, 4);
    bintree_setdata(e, 5);
    bintree_setdata(f, 6);

    bintree_make_left(a, b);
    bintree_make_right(a, c);
    bintree_make_left(b, d);
    bintree_make_right(b, e);
    bintree_make_left(c, f);

    inorder_traverse(a);
    printf("\n");
    preorder_traverse(a);
    printf("\n");
    postorder_traverse(a);
    return 0;
}