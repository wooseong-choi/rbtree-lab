#include "rbtree.h"
#include <stdio.h>
#include <stdlib.h>

rbtree *new_rbtree(void) {
  rbtree *p = (rbtree *)calloc(1, sizeof(rbtree));
  p->nil = (node_t*)calloc(1,sizeof(node_t));
  p->nil->color = RBTREE_BLACK;
  p->nil->left = NULL;
  p->nil->right = NULL;
  p->nil->parent = NULL;

// 삽입시 node를 생성하여 넣어줄 것이기 때문에 메모리 할당 필요 없다.
  p->root = NULL;
  p->root = p->nil;
  p->root->left = NULL;
  p->root->right = NULL;
  p->root->parent = NULL;

  return p;
}

void delete_rbtree(rbtree *t) {
  // TODO: reclaim the tree nodes's memory
  free(t);
}

node_t *rbtree_insert(rbtree *t, const key_t key) {
  // TODO: implement insert
  node_t *tempNode = t->root ;
  if (t->root == NULL){
    t->root = malloc(sizeof(node_t));
    t->nil = malloc(sizeof(node_t));
    if ( t->root != NULL){
      t->nil->left = malloc(sizeof(node_t));
      t->nil->right = malloc(sizeof(node_t));
      t->root->key = key;
      t->root->left = t->nil->left;
      t->root->right = t->nil->right;
      t->root->parent = NULL;
    }
  }else{
    if (key < 0){

    }
  }

  return t->root;
}

node_t *rbtree_find(const rbtree *t, const key_t key) {
  // TODO: implement find
  return t->root;
}

node_t *rbtree_min(const rbtree *t) {
  // TODO: implement find
  return t->root;
}

node_t *rbtree_max(const rbtree *t) {
  // TODO: implement find
  return t->root;
}

int rbtree_erase(rbtree *t, node_t *p) {
  // TODO: implement erase
  return 0;
}

int rbtree_to_array(const rbtree *t, key_t *arr, const size_t n) {
  // TODO: implement to_array
  return 0;
}
