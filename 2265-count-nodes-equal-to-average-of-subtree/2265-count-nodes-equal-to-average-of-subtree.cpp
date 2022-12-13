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
    int total=0;
    pair<int,int> solve(TreeNode* root, unordered_set<int>s, int sum,int node)
    {
        if(!root)return {0,0};
        if(root->left==NULL and root->right==NULL)
        {
            total++;
            s.insert(root->val);
            return {root->val,1};
        }
        
        auto left=solve(root->left,s,sum,node);
        auto right=solve(root->right,s,sum,node);
        
        int tot_sum=left.first+right.first+ root->val;
        int tot_node=left.second+right.second+1;
        int avg=tot_sum/tot_node;
        s.insert(root->val);
        if(s.find(avg)!=s.end())total++;
        
        return {tot_sum,tot_node};   
    }
    int averageOfSubtree(TreeNode* root) {
        
        unordered_set<int> st;
        solve(root,st,0,0);
        return total;
    }
};