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
    ListNode* partition(ListNode* head, int x) {
        
        ListNode* gret = new ListNode(-1);
        ListNode* smal = new ListNode(-1);
        ListNode* tmp=gret, *ans=smal;
        ListNode* root=head;
        while(root!=NULL)
        {
            if(root->val>=x)
            {
                gret->next=new ListNode(root->val);
                gret=gret->next;
            }
            else
            {
                smal->next=new ListNode(root->val);
                smal=smal->next;
            }
            root=root->next;
        }
        
        smal->next=tmp->next;     
        return ans->next;

    }
};