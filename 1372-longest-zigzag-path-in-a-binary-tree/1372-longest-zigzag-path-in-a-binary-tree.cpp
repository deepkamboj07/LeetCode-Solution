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

    int ans=0;
    int solve(TreeNode* root, bool left,int len)
    {
        if(!root)return 0;
        int l=0,r=0,ll=0,rr=0;
        ans=max(ans,len);
        if(!left)
        {
            l=1+solve(root->left,true,len+1);
            rr=solve(root->right,true,0);
        }
        else
        {
           ll=solve(root->left,false,0);
            r=1+solve(root->right,false,len+1);
        }
        
        return max({l,r,ll,rr});
    }
    int longestZigZag(TreeNode* root) {
        
        ans=0;
        int zigzack=max(solve(root,true,0), solve(root,false,0));
        return ans;
    }
};