/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int count=0;
        ListNode* head2=head;
        ListNode* head3=head;
        while(head2){
            count++;
            head2=head2->next;
        }
        cout<<count<<endl;
        count=count/2;
        while(count){
            head3=head3->next;
            count--;
        }
        return head3;
    }
};