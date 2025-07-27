#include "in2post.h"
#include "exptree.h"
#include <stdio.h>
#include <string.h>

#define MAXLEN 100

int main(void){
    char src[MAXLEN];
    char dst[MAXLEN];
    scanf("%s", src);

    // Convert to postfix expression
    in2post(dst, src);

    // Create expression tree
    struct node* exptree = exptree_make(dst);
    display_inorder(exptree);
    printf("\n");

    // Calculate exptree
    int res = exptree_cal(exptree);
    printf("result: %d\n", res);

    return 0;
}