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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        stack<ListNode*> st1,st2,ans;
        
        while(l1!=NULL)
        {
            st1.push(l1);
            l1=l1->next;
        }
        while(l2!=NULL)
        {
            st2.push(l2);
            l2=l2->next;
        }
        
        if(st1.size()<st2.size())
        {
            stack<ListNode*> tmp;
            tmp=st1;
            st1=st2;
            st2=tmp;
        }
        
        int carry=0;
        while(!st2.empty())
        {
            int sum=st1.top()->val + st2.top()->val +carry;
            carry=sum/10;
            sum%=10;
            ans.push(new ListNode(sum));
            st1.pop();st2.pop();
        }
        while(!st1.empty())
        {
            int sum=st1.top()->val+carry;
            carry=sum/10;
            sum%=10;
            ans.push(new ListNode(sum));
            st1.pop();
        }
        
        if(carry!=0)
            ans.push(new ListNode(carry));
        
        l1=new ListNode(-1);
        l2=l1;
        while(!ans.empty())
        {
            l1->next=ans.top();
            ans.pop();
            l1=l1->next;
        }
        return l2->next;
    }
};