#include "rbtree.h"
#include "rbtree.c"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    rbtree *t = new_rbtree();
    // node_t *p = rbtree_insert(t, 26);
    for (int i = 1; i < 16; i++)
    {
        rbtree_insert(t, i);
        /* code */
    }
    
    // rbtree_insert(t, 17);
    // rbtree_insert(t, 41);
    // rbtree_insert(t, 47);
    // rbtree_insert(t, 21);
    rbtree_to_print(t->root,t->nil);
    printf("\n");
}