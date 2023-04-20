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
        ListNode* prev=NULL;
        while(head!=NULL and head->next!=NULL)
        {
            if(head->val == head->next->val)
            {
                while(head->next!=NULL and head->val == head->next->val)
                {
                    head=head->next;
                }
                if(prev)
                {
                    prev->next=head->next;
                    head=prev->next;
                }
                else
                {
                    root=head->next;
                    head=head->next;
                }
            }
            else
            {
                prev=head;
                head=head->next;
            }
        }
        
        return root;
    }
};