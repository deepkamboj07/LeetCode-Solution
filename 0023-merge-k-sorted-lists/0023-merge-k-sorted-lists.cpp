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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int,vector<int>,greater<int>> pq;
        int n=lists.size();
        
        for(int i=0;i<n;i++)
        {
            ListNode*tmp=lists[i];
            while(tmp!=NULL)
            {
                pq.push(tmp->val);
                tmp=tmp->next;
            }
        }
        
        ListNode *head=new ListNode(-1);
        ListNode* ans=head;
        
        while(!pq.empty())
        {
            ListNode *tmp= new ListNode(pq.top());
            pq.pop();
            head->next=tmp;
            head=head->next;
        }
        return ans->next;
        
    }
};