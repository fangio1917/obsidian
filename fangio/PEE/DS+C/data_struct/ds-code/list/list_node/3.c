#include "list_node.h"

void ReverseList(pListNode head) {
    if (head == NULL || head->next == NULL) return;
    
    pListNode p = head->next;
    pListNode q = p->next;
    
    // 第一个节点将成为最后一个节点，需要将其next置为NULL
    p->next = NULL;
    
    // 反转链表
    while (q != NULL) {
        pListNode r = q->next;
        q->next = p;
        p = q;
        q = r;
    }
    
    // 更新头节点的next指针指向新的第一个节点
    head->next = p;
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    pListNode head = initListNode(arr,10);
    ReverseList(head);
    displayListNode(head);
    return 0;
}