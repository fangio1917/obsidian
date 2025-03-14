#include "list_node.h"

pListNode SplitList(pListNode head) {
    if (head == NULL || head->next == NULL) {
        return NULL;
    }

    pListNode list_b_head = malloc(sizeof(ListNode));
    list_b_head->next = NULL;
    pListNode list_b = list_b_head;
    pListNode list_a = head;

    while (list_a->next != NULL && list_a->next->next != NULL) {
        list_b->next = list_a->next;
        list_a->next = list_a->next->next;
        list_b = list_b->next;
        list_b->next = NULL;
        list_a = list_a->next;
    }

    return list_b_head;
}


int main(){
    int arr[] = {1,2,1,2,1,2,1,2};
    pListNode head = initListNode(arr,sizeof(arr)/sizeof(int));
    pListNode list_b = SplitList(head);
    displayListNode(head);
    displayListNode(list_b);
    return 0;
}