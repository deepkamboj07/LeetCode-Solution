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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool nullCount=false;
        
        while(!q.empty())
        {
            TreeNode* top=q.front();
            q.pop();
            
            if(top==NULL)nullCount=true;
            else
            {
                if(nullCount)return false;
                q.push(top->left);
                q.push(top->right);
            }
        }
        
        return true;
    }
};