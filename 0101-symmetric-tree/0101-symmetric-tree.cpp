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
    bool solve(TreeNode* a, TreeNode* b){
        if(a==NULL || b==NULL)
            return a==b;
        if(a->val!=b->val) return false;
        return solve(a->left,b->right) and solve(a->right,b->left);
    }
    bool isSymmetric(TreeNode* root) {
        return solve(root->left , root->right);
    }
};