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
    TreeNode* prev=nullptr;
    void solve(TreeNode* root)
    {
        if(!root)return;
        
        solve(root->left);
        if(prev)ans=min(ans, abs(prev->val - root->val));
        prev=root;
        solve(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        solve(root);
        return ans;
    }
};