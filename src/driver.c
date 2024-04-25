#include "rbtree.h"
#include "rbtree.c"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // rbtree *t = new_rbtree();
    // // node_t *p = rbtree_insert(t, 26);
    // // key_t entries[] = {10, 5, 8, 34, 67};
    // key_t entries[] = {10, 5, 8, 34, 67, 23, 156, 24, 2, 12, 24, 36, 990, 25};
    // const size_t n = sizeof(entries) / sizeof(entries[0]);
    // for (int i = 0; i < n; i++)
    // {
    //     rbtree_insert(t, entries[i]);
    //     /* code */
    // }
    // printf("최초 트리 리스트 출력");
    // rbtree_to_print(t->root,t->nil);
    ////////////////////////////////////////////////////
    // delete test
    // for (int i = 0; i < 3; i++)
    // {   
    //     node_t *p = rbtree_find(t, entries[i]);
    //     // printf("arr[%d] = %d\n", i, arr[i]);
    //     // assert(p != NULL);
    //     // assert(p->key == arr[i]);
    //     rbtree_erase(t, p);
        
    //     printf("%d 키-", p->key);
    //     printf("%d 번째 출력\n", i+1);
    //     rbtree_to_print(t->root,t->nil);
    // }
    
    /////////////////////////////////////////////////////
    // node_t *temp_min = rbtree_min(t);
    // node_t *temp_max = rbtree_max(t);
    // printf("^.^ %d ", temp_min->key);
    // printf("^_^ %d ", temp_max->key);
    ////////////////////////////////////////////////////
    // printf("111111");
    // rbtree *t = new_rbtree();
    // key_t entries[] = {10, 5, 8, 34, 67, 23, 156, 24, 2, 12, 24, 36, 990, 25};
    // const size_t n = sizeof(entries) / sizeof(entries[0]);
    // printf("작동test");
    // for (int i = 0; i < n; i++)
    // {
    //     rbtree_insert(t, entries[i]);
    //     /* code */
    // }

    // insert_arr(t, entries, n);
    // qsort((void *)entries, n, sizeof(key_t), comp);

    // key_t *res = calloc(n, sizeof(key_t));
    // printf("작동1");
    // rbtree_to_array(t, res, n);
    // printf("작동이후");
    // for (int i = 0; i < n; i++) {
    //     (entries[i] == res[i])?printf("1"):printf("0");
    // }
    // free(res);
    printf("\n");
}

// #include <stdio.h>
// int main()
// {
// int numArr[5] = { 11, 22, 33, 44, 55 };
// int *numPtrA;
// void *ptr;
// numPtrA = &numArr[2];

// ptr = numArr;
// printf("%d\n", *(numPtrA+2));
// printf("%d\n",*((int *)ptr+1));
// return 0;
// }

// #include <stdio.h>
// int main() {
// char* str[2];
// str[0] = "hello!";
// str[1] = "jungler";
// printf("1. %s\n", str[0] + 1);
// printf("2. %s\n", (str + 1)[0] + 2);
// return 0;
// }