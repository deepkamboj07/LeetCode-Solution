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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* root=head;
        while(head)
        {
            ListNode* tmp=head;
            while(tmp->next and tmp->next->val==tmp->val)
            {
                tmp=tmp->next;
            }
            if(tmp==head)head=head->next;
            else
            {
                cout<<tmp->val<<" ";
                head->next=tmp->next;
                head=head->next;
            }
        }
        
        return root;
    }
};