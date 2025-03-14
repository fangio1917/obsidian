#ifndef _LIST_NODE_H_
#define _LIST_NODE_H_

#define MAX_INT 0x7fffffff
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct ListNode {
  int val;
  struct ListNode *next;
} ListNode,*pListNode;


// 接受一个数组，并返回一个链表
pListNode initListNode(int *arr,int len){
 //带头节点，尾插
  pListNode head = (pListNode)malloc(sizeof(ListNode));
  head->next = NULL;
  pListNode tail = head;
  for (int i = 0; i < len; i++) {
    pListNode node = (pListNode)malloc(sizeof(ListNode));
    node->val = arr[i];
    node->next = NULL;
    tail->next = node;
    tail = node;
  }
  return head;
}

void displayListNode(pListNode head){
  if (head == NULL) {
    printf("List is empty\n");
    return;
  }
  head = head->next;
  while (head){
    printf("%d ", head->val);
    head = head->next;
  }
  printf("\n");
}

void destroyListNode(pListNode head){
  pListNode p = head;
  while (p){
    pListNode q = p->next;
    free(p);
    p = q;
  }
}

#endif