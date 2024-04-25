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

  // printf("rb_tree 생성\n");
  return p;
}
void delete_rbtree_recursive( node_t *cur, node_t *nil ){
  if(cur == nil){
    return;
  }
  delete_rbtree_recursive(cur->left,nil);
  delete_rbtree_recursive(cur->right,nil);
  free(cur);
}

void delete_rbtree(rbtree *t) {
  // TODO: reclaim the tree nodes's memory

  delete_rbtree_recursive(t->root, t->nil);
  free(t->nil);

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
  // free(y);
  // free(z);
  return t->root;
}


node_t *rbtree_find(const rbtree *t, const key_t key) {
  // TODO: implement find
  node_t *temp = t->root;
  node_t *result = NULL;

  while (temp != t->nil)
  {
    if(temp->key > key){
      temp = temp->left;
    }else if(temp->key < key){
      temp = temp->right;
    }else{
      // find!
      result = temp;
      break;
    }
  }
  return result;
}

node_t *rbtree_min(const rbtree *t) {
  // TODO: implement find
  node_t *temp = t->root;
  node_t *result = temp;
  // int min = result->key;
  while (temp != t->nil)
  {
    if (temp->left != t->nil)
      temp = temp->left;
    else {
      result = temp;
      break;
    }

  }
  return result;
}


node_t *rbtree_max(const rbtree *t) {
    // TODO: implement find
  node_t *temp = t->root;
  node_t *result = temp;
  // int min = result->key;
  while (temp != t->nil)
  {
    if (temp->right != t->nil)
      temp = temp->right;
    else {
      result = temp;
      break;
    }

  }
  return result;
}

node_t *rbtree_min_in_choice(const rbtree *t, node_t * cur) {
  // TODO: implement find
  node_t *temp = cur->right;
  node_t *result = temp;
  // int min = result->key;

  while (temp != t->nil)
  {
    if(temp->left != t->nil){
      temp = temp->left;
    }else{
      // find!
      result = temp;
      break;
    }
  }
  return result;
}


void rbtree_erase_fixup(rbtree * t, node_t *x){
  node_t *s; // 형제선언
  while (x != t->root && x->color == RBTREE_BLACK) // 대상이 루트가 아니고 빨갈때
  {
    if(x == x->parent->left) { // 대상이 대상의 부모 에서 봤을때 왼쪽 형제이면
      s = x->parent->right; // 형제
      if(s->color == RBTREE_RED){ // 형제가 붉을 때
        s->color = RBTREE_BLACK; // 부모 색 빨아들임
        x->parent->color = RBTREE_RED; // 색을 뺏겨서 빨개짐
        left_rotate(t,x->parent); // 부모기준 좌회전
        s = x->parent->right;
      }
      if( s->left->color == RBTREE_BLACK && s->right->color == RBTREE_BLACK ){ // 두 자식이 붉으면
        s->color = RBTREE_RED; // 쭈왑당함
        x = x->parent;
      }else{
        if(s->right->color == RBTREE_BLACK){ // 내 오른자식이 검으면 꺾돌바
          s->left->color = RBTREE_BLACK;
          s->color = RBTREE_RED;
          right_rotate(t, s); // 내기준 우회전
          s = x->parent->right;
        }
        s->color = x->parent->color;
        x->parent->color = RBTREE_BLACK;
        s->right->color = RBTREE_BLACK;
        left_rotate(t, x->parent);
        x = t->root;      
      } 
    }else{
      s = x->parent->left; // 형제
      if(s->color == RBTREE_RED){ // 형제가 붉을 때
        s->color = RBTREE_BLACK; // 부모 색 빨아들임
        x->parent->color = RBTREE_RED; // 색을 뺏겨서 빨개짐
        right_rotate(t,x->parent); // 부모기준 우회전
        s = x->parent->left;
      }
      if( s->left->color == RBTREE_BLACK && s->right->color == RBTREE_BLACK ){ // 두 자식이 붉으면
        s->color = RBTREE_RED; // 쭈왑당함
        x = x->parent;
      }else{
        if(s->left->color == RBTREE_BLACK){ // 내 오른자식이 검으면 꺾돌바
          s->right->color = RBTREE_BLACK;
          s->color = RBTREE_RED;
          left_rotate(t, s); // 내기준 우회전
          s = x->parent->left;
        }
        s->color = x->parent->color;
        x->parent->color = RBTREE_BLACK;
        s->left->color = RBTREE_BLACK;
        right_rotate(t, x->parent);
        x = t->root;
      } 
    }
  }

  x->color = RBTREE_BLACK; // 루트
}

void rbtree_transplant(rbtree *t, node_t *cur, node_t *right){
  // printf( "   is cur %d\n", cur->key);
  // printf("    is right %d\n", right->key);
  // printf(" before p.right %d\n", cur->parent->right->key);
  if(cur->parent == t->nil){ // 루트면
    t->root = right;
  }else if(cur == cur->parent->left){ // 부모의 왼쪽 자식이면
    cur->parent->left = right;
  }else{ // 부모의 오른쪽 자식이면
    
    cur->parent->right = right;
  // printf(" after p.right %d\n", cur->parent->right->key);
  }
  // printf(" before r p.right %d\n", right->parent->key);
  right->parent = cur->parent;
  // printf(" after r p.right %d\n", right->parent->key);
}

int rbtree_erase(rbtree *t, node_t *p) {
  node_t * tempY = p;
  node_t * tempX;
  color_t temp_origin_color = tempY->color;
  printf("target key = %d\n" , p->key);
  printf("target left key = %d\n" , p->left->key);
  printf("target right key = %d\n" , p->right->key);
  if(p->left == t->nil){
    tempX = p->right;
    printf("tempx key = %d\n" , tempX->key);
    rbtree_transplant(t, p,p->right);
  }else if(p->right == t->nil){
    tempX = p->left;
    printf("else if key = %d\n" , p->key);
    rbtree_transplant(t, p,p->left);
  }else{
    printf("else 들어옴 key = %d\n" , p->key);
    tempY = rbtree_min_in_choice(t, tempY); // 오른 트리에서 제일 작은값 찾아
    temp_origin_color = tempY->color; 
    tempX = tempY->right;
    if(tempY->parent == p){
      tempX->parent = tempY;
    }else {
      printf("else key = %d\n" , p->key);
      rbtree_transplant( t, tempY, tempY->right );
      tempY->right = p->right;
      tempY->right->parent = tempY;
    }
    printf("if빠져나옴 key = %d\n" , p->key);
    rbtree_transplant(t, p, tempY);
    tempY->left = p->left;
    tempY->left->parent = tempY;
    tempY->color = p->color;
  }
  if(temp_origin_color == RBTREE_BLACK){
    printf("진입하겠음 key = %d\n" , p->key);
    rbtree_erase_fixup(t,tempX);
  }

  free(p);
  return 1;
}

// int recursion_temp = 0;

void recursive_to_array(const rbtree *t, node_t *cur, key_t *arr, int* n){
  // printf("recursive_to_arr%d\n", *temp);
  if (cur == t->nil){
    return;
  }

  recursive_to_array(t, cur->left, arr, n);
  // printf("재귀번호, %d 값 %d\n", recursion_temp,cur->key);
  // printf("뀨 %d", *n);
  // arr[recursion_temp++] = cur->key;
  arr[(*n)++] = cur->key;
  recursive_to_array(t, cur->right, arr, n);
}

int rbtree_to_array(const rbtree *t, key_t *arr, const size_t n) {
  // TODO: implement to_array
  int i = 0;
  recursive_to_array(t,t->root,arr, &i);
  // printf("재귀 끝");
  
  // for (int i = 0; i < n; i++) {
  //   // printf("is arr tostring %d \n",arr[i]);
  // }

  // recursion_temp = 0;
  return 0;
}


void rbtree_to_print(node_t *t, node_t * nil) {
  // TODO: implement to_print
  // printf("t.print 진입\n");

  if( t == nil ){
    return;
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

void printTree(rbtree *t, node_t *cur, int level, int isLeft) {
    if (cur == t->nil) {
        return;
    }

    // 오른쪽 자식 노드 출력
    printTree(t, cur->right, level + 1, 0);

    // 현재 노드 출력
    for (int i = 0; i < level - 1; i++) {
        printf("    ");
    }
    if (level > 0) {
        printf(isLeft ? " \\_ " : " /⎺ ");  // 왼쪽 자식일 경우 "\\" 출력, 오른쪽 자식일 경우 "/" 출력
    }
    if (cur->color == RBTREE_RED)
    {
      printf("\x1b[31m%d\x1b[0m\n", cur->key);
    }
    else{
      printf("%d\n", cur->key);
    }

    // 왼쪽 자식 노드 출력
    printTree(t, cur->left, level + 1, 1);
}