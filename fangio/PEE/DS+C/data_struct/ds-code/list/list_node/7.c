#include "list_node.h"

void Deduplicate(pListNode head){
    pListNode p = head->next;

    while(p->next != NULL){
        if(p->next->val == p->val){
            p->next = p->next->next;
        }else{
            p = p->next;
        }
    }

}


int main(){
    int arr[] = {1,2,2,3,3,4,5,5,6,7,7,8,9,9,10,10};
    int len = sizeof(arr) / sizeof(arr[0]);
    pListNode head = initListNode(arr,len);
    Deduplicate(head);
    displayListNode(head);
    return 0;
}