/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
   /* int length(ListNode* head)
    {   int count=0;
        if(head->next==NULL)
            return NULL;
        else
        {
            while(head->next!=NULL)
            {
                count++;
                head=head->next;
            }
        }
        return count;
    }  */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a = headA, *b = headB;
        while (a != b) {
            a = !a ? headB : a->next;
            b = !b ? headA : b->next;
        }
        return a;
    }
};