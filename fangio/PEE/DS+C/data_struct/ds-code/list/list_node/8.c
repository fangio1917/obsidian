#include "list_node.h"

pListNode GetPublishList(pListNode head_1, pListNode head_2)
{
    pListNode new_head = malloc(sizeof(ListNode));
    new_head->next = NULL;

    pListNode list_1 = head_1->next;
    pListNode list_2 = head_2->next;
    pListNode list_n = new_head;

    while (list_1 != NULL && list_2 != NULL)
    {
        if (list_1->val == list_2->val)
        {
            pListNode new_node = malloc(sizeof(ListNode));
            new_node->val = list_1->val;
            list_n->next = new_node;
            list_n = list_n->next;
            list_n->next = NULL;

            list_1 = list_1->next;
            list_2 = list_2->next;
        }
        else if (list_1->val < list_2->val)
        {
            list_1 = list_1->next;
        }
        else
        {
            list_2 = list_2->next;
        }
    }

    return new_head;
}

int main()
{
    printf("hello world\n");
    int arr_1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr_2[] = {1, 3, 5, 7, 9};
    pListNode head_1 = initListNode(arr_1, sizeof(arr_1) / sizeof(arr_1[0]));
    pListNode head_2 = initListNode(arr_2, sizeof(arr_2) / sizeof(arr_2[0]));

    pListNode new_head = GetPublishList(head_1, head_2);

    
    displayListNode(new_head);
    destroyListNode(head_1);
    destroyListNode(head_2);
    destroyListNode(new_head);

    return 0;
}