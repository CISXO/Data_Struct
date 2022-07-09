#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
   struct Node *llink;
  int data;
   struct Node *rlink;
} Node;

Node *head;
Node *tail;

Node *makenode(int val) {
  Node *node1 = (Node*)malloc(sizeof(Node));
  node1->llink = NULL;
  node1->data = val;
  node1->rlink = NULL;
  return node1;
}

void printlist() {
  Node *p;
  p = head;
  while(p->rlink != tail) {
    printf("%d->",p->data);
    p=p->rlink;
  }
  printf("%d->", p->data);
}

void init() {
  head = (Node*)malloc(sizeof(Node));
  tail = (Node*)malloc(sizeof(Node));
  head->data = 0;
  tail->data = 0;

  head->rlink = tail;
  head->llink = head;
  tail->rlink = tail;
  tail->llink = head;

}

void insert_node(int val) {
  Node *newNode = makenode(val);
  Node *p;
  p= tail;
  p->llink->rlink = newNode;
  newNode->llink = p -> llink;
  p-> llink = newNode;
  newNode -> rlink = p;
}

int main () {

  init();
  insert_node(10);

  insert_node(30);
  insert_node(40);
    printlist();
  return 0;
}
