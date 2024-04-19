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
  p->root = p->nil;

  printf("rb_tree 생성\n");
  return p;
}

void delete_rbtree(rbtree *t) {
  // TODO: reclaim the tree nodes's memory
  free(t);
}

void left_rotate(rbtree *t ,node_t *n){
  // printf("좌회전\n");
  node_t *y = n->right; // y 설정
  n->right = y->left; // y의 왼쪽 서브트리 x의 오른 서브트리로
  if(y->left != t->nil){
    y->left->parent = n;
  }
  y->parent = n->parent; // x 부모 y로 바꾸기
  if( n->parent == t->nil){
    t->root = y;
  }else if (n == n->parent->left){
    n->parent->left = y;
  }else{
    n->parent->right = y;
  }
  y->left = n; // x를 y의 왼쪽으로
  n->parent = y;
}

void right_rotate(rbtree *t ,node_t *n){
  // printf("우회전\n");
  node_t *y = n->left; // y 설정
  n->left = y->right; // y의 오른쪽 서브트리 x의 왼 서브트리로
  if(y->right != t->nil){
    y->right->parent = n;
  }
  y->parent = n->parent; // x 부모 y로 바꾸기
  if( n->parent == t->nil){
    t->root = y;
  }else if (n == n->parent->right){
    n->parent->right = y;
  }else{
    n->parent->left = y;
  }
  y->right = n; // x를 y의 오른쪽으로
  n->parent = y;
}


void rbtree_insert_fixup( rbtree *t, node_t *z ){
  // printf("입장\n");
  node_t *y;
  while (z->parent->color == RBTREE_RED)
  {
    if(z->parent == z->parent->parent->left){
      // printf("순");
      // 왼
      y = z->parent->parent->right;
      if(y->color == RBTREE_RED){
        z->parent->color = RBTREE_BLACK;
        y->color = RBTREE_BLACK;
        z->parent->parent->color = RBTREE_RED;
        z = z->parent->parent;
        continue;
      }else if(z == z->parent->right){
        z = z->parent;
        left_rotate(t,z);
      }
      z->parent->color = RBTREE_BLACK;
      z->parent->parent->color = RBTREE_RED;
      right_rotate(t,z->parent->parent);

    }else{
      // printf("반");
      // 오
      y = z->parent->parent->left;
      if(y->color == RBTREE_RED){
        z->parent->color = RBTREE_BLACK;
        y->color = RBTREE_BLACK;
        z->parent->parent->color = RBTREE_RED;
        z = z->parent->parent;
        continue;
      }else if(z == z->parent->left){
        z = z->parent;
        right_rotate(t,z);
      }
      z->parent->color = RBTREE_BLACK;
      z->parent->parent->color = RBTREE_RED;
      left_rotate(t,z->parent->parent);
    
    }

  }
  t->root->color = RBTREE_BLACK;
}  

node_t *rbtree_insert(rbtree *t, const key_t key) {
  // TODO: implement insert
  node_t *y = t->nil;
  node_t *x = t->root;
  
  // printf("여긴 됬을거야 \n");
  node_t *z = (node_t*)calloc(1,sizeof(node_t));
  z->color = RBTREE_RED;
  z->key = key;
  while (x != t->nil)
  {
    y = x;
    if (z->key < x->key){
      x = x->left;
    }else{
      x = x->right;
    }
  }
  z->parent = y;
  // printf("여기까지는 되어야지\n");
  if(y == t->nil){
    t->root = z;
  }else if( z->key < y->key){
    y->left = z;
  }else{
    y->right = z;
  }
  z->left = t->nil;
  z->right = t->nil;
  // printf("일단 여기까진 됬어\n");
  rbtree_insert_fixup(t, z);
  // printf("뀨\n");
  
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

void rbtree_to_print(node_t *t, node_t * nil) {
  // TODO: implement to_print
  // printf("t.print 진입\n");

  if( t == nil ){
    // return 0;
  }

  if (t != nil){
    printf("t.print %d\n",t->key);
  }
  if(t->left != nil){
    rbtree_to_print(t->left, nil);
  }
  if(t->right != nil){
    rbtree_to_print(t->right, nil);
  }
  // return 0;
}
