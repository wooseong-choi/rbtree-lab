#include "rbtree.h"
#include "rbtree.c"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    rbtree *t = new_rbtree();
    // node_t *p = rbtree_insert(t, 26);
    // key_t entries[] = {10, 5, 8, 34, 67};
    key_t entries[] = {10, 5, 8, 34, 67, 23, 156, 24, 2, 12, 24, 36, 990, 25};
    const size_t n = sizeof(entries) / sizeof(entries[0]);
    for (int i = 0; i < n; i++)
    {
        rbtree_insert(t, entries[i]);
        /* code */
    }
    printf("최초 트리 리스트 출력");
    rbtree_to_print(t->root,t->nil);
    for (int i = 0; i < 3; i++)
    {   
        node_t *p = rbtree_find(t, entries[i]);
        // printf("arr[%d] = %d\n", i, arr[i]);
        // assert(p != NULL);
        // assert(p->key == arr[i]);
        rbtree_erase(t, p);
        
        printf("%d 키-", p->key);
        printf("%d 번째 출력\n", i+1);
        rbtree_to_print(t->root,t->nil);
    }
    
    // rbtree_insert(t, 17);
    // rbtree_insert(t, 41);
    // rbtree_insert(t, 47);
    // rbtree_insert(t, 21);
    printf("\n");
}