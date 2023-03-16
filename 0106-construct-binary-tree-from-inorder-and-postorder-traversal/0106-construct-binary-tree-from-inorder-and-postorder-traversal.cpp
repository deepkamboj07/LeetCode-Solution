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
    TreeNode* construct(vector<int>&in, int instart,int inend, vector<int>&post, 
                        int poststart,int postend, map<int,int>&mp){
        
        if(instart>inend || poststart>postend)
            return NULL;
        
        TreeNode* root= new TreeNode(post[postend]);
        int pos=mp[root->val];
        int cur=pos-instart;
        root->left=construct(in,instart,pos-1,post,poststart,poststart+cur-1,mp);
        root->right=construct(in,pos+1,inend,post,poststart+cur,postend-1,mp);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> mp;
        int n=inorder.size()-1;
        for(int i=0;i<=n;i++)
            mp[inorder[i]]=i;
        return construct(inorder,0,n,postorder,0,n,mp);
    }
};