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
    int length(ListNode* head)
    {
        int count=0;
        while(head!=NULL)
        {
            count++;
            head=head->next;
        }
        return count;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        int len=length(head);
        int back=len-k+1;
        //cout<<k<<" "<<back;
        if(k==back)
            return head;
        
        int i=1,j=1;
        ListNode* tmp=head;
        ListNode* tmp2=head;
        while(i<k || j<back)
        {
            if(i<k)
            {
                tmp=tmp->next;
                i++;
            }
            if(j<back)
            {
                tmp2=tmp2->next;
                j++;
            }
            
        }
        
        swap(tmp->val,tmp2->val);
        
        return head;
    }
};