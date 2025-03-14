#include "list_node.h"

void GetIntersection(pListNode head_1, pListNode head_2)
{

    pListNode list_1 = head_1;
    pListNode list_2 = head_2;

    while (list_1->next != NULL && list_2->next != NULL)
    {
        if (list_1->next->val == list_2->next->val)
        {
            list_1 = list_1->next;
            pListNode del = list_2->next;
            list_2->next = del->next;
            free(del);
        }
        else if (list_1->next->val < list_2->next->val)
        {
            pListNode del = list_1->next;
            list_1->next = del->next;
            free(del);
        }
        else
        {
            pListNode del = list_2->next;
            list_2->next = del->next;
            free(del);
        }
    }

    while(list_1 ->next!= NULL){
        pListNode del = list_1->next;
        list_1->next = del->next;
        free(del);
    }
    while(list_2 ->next!= NULL){
        pListNode del = list_2->next;
        list_2->next = del->next;
        free(del);
    }

}

int main()
{

    int arr_1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int arr_2[] = {1, 3, 5, 7, 9};
    pListNode head_1 = initListNode(arr_1, sizeof(arr_1) / sizeof(arr_1[0]));
    pListNode head_2 = initListNode(arr_2, sizeof(arr_2) / sizeof(arr_2[0]));

    GetIntersection(head_1, head_2);

    displayListNode(head_1);

    
    destroyListNode(head_1);
    destroyListNode(head_2);

    return 0;
}