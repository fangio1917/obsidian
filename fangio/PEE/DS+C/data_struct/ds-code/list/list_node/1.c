#include "list_node.h"

// DelVal函数内不要进行自动补全
void DelVal(pListNode head, int val)
{
    if (head == NULL)
        return;

    pListNode cur = head;
    while (cur->next != NULL)
    {
        if (cur->next->val == val)
        {
            pListNode del = cur->next;
            cur->next = cur->next->next;
            free(del);
        }
        else
        {
            cur = cur->next;
        }
    }
}

int main()
{
    int arr[] = {3, 3, 3, 3, 3, 3, 3, 3};
    ListNode *head = initListNode(arr, sizeof(arr) / sizeof(arr[0]));
    DelVal(head, 3);

    displayListNode(head);
    free(head);
}