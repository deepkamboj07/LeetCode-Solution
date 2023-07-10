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
    int mini=1e9;
    void solve(TreeNode* root,int tmp)
    {
        if(root==NULL)return;
        if(root->left==NULL and root->right==NULL)
        {
            mini=min(tmp,mini);
            return;
        }
        
        solve(root->left,tmp+1);
        solve(root->right,tmp+1);
    }
    int minDepth(TreeNode* root) {
        solve(root,1);
        return (mini==1e9)?0:mini;
    }
};