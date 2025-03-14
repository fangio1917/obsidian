#include "list_node.h"

void DelMinVel(pListNode head){
    if(head == NULL)
        return;
    int min = MAX_INT;

    pListNode p = head->next;
    int index  = 0,mark = 0;

    while (p != NULL)
    {
        if(p->val < min){
            min = p->val;
            mark = index;
        }
        p = p->next;
        index++;
    }

    p = head;
    for (int i = 0;i<mark;i++){
        p = p->next;
    }

    pListNode del = p->next;
    p->next = del->next;
    free(del);
}


int main(){
    int arr[] = {8,100,9,10,2,3,4,5,6,7,100};
    pListNode head = initListNode(arr,sizeof(arr)/sizeof(arr[0]));
    DelMinVel(head);
    displayListNode(head);
    free(head);
    return 0;
}