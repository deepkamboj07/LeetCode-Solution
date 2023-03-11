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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    TreeNode* makeBST(vector<int>&arr, int start, int end)
    {
        if(start>end)
        {
            return NULL;
        }
        if(start==arr.size())
            return NULL;
        int mid=((start+end)/2);
             
        TreeNode* root=new TreeNode(arr[mid]);
        
        root->left=makeBST(arr,start,mid-1);
        root->right=makeBST(arr,mid+1,end);      
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int>arr;
        while(head!=NULL)
        {
            arr.push_back(head->val);
            head=head->next;
        }
       
        return makeBST(arr,0,arr.size());
    }
};