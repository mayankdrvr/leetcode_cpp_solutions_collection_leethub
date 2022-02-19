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
        stack<ListNode*> st;
        ListNode* p=head;
        while(p){
            st.push(p);
            p=p->next;
        }
        p=head;
        for(int i=0;i<st.size()/2;i++){
            p=p->next;
        }
        return p;
    }
};