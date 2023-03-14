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
    int ans=0,num=0;
    int traversal(TreeNode *root,int s){
      if(root==NULL)
        return 0;
      if(root->left==NULL && root->right==NULL)
      {
          return s*10+root->val;
      }
      else
        return traversal(root->left,s*10+root->val) + traversal(root->right,s*10+root->val);
      
     
    }
    int sumNumbers(TreeNode* root) {
      
        return traversal(root,0);
        
    }
};