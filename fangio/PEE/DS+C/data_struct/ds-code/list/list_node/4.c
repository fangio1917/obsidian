#include "list_node.h"

void DelVal(pListNode node){
    pListNode del = node->next;
    node->next = del->next;
    free(del);
}

void DelRange(pListNode head, int left, int right){
    if(head == NULL)
        return;

    pListNode p = head;

    while(p->next != NULL){
        if(p->next->val >= left && p->next->val <= right){
            DelVal(p);
        }else{
            p = p->next;
        }
    }
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    pListNode head = initListNode(arr,10);
    DelRange(head,3,7);
    displayListNode(head);
    return 0;
}