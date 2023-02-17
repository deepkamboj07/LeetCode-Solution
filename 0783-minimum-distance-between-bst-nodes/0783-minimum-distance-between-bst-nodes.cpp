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
    int ans=1e9;
    void solve(TreeNode* root, TreeNode*&prev)
    {
        if(!root)return;
        solve(root->left,prev);
        if(prev)ans=min(ans, abs(root->val-prev->val));
        prev=root;
        solve(root->right,prev);
    }
    int minDiffInBST(TreeNode* root) {
        TreeNode* prev=NULL;
        solve(root,prev);
        return ans;
    }
};