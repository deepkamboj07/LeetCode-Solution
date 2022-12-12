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
    unordered_set<TreeNode*> ans;
    void solve(TreeNode*&root,unordered_set<int>&st)
    {
        if(!root)return;
        
        solve(root->left,st);
        solve(root->right,st);
        
        if(st.find(root->val) != st.end())
        {
            if(root->left)ans.insert(root->left);
            if(root->right)ans.insert(root->right);
            root=NULL;
            //return;
        }
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        
        unordered_set<int> st(to_delete.begin(), to_delete.end()); 
        TreeNode* head=root;
        solve(head,st);
        if(head)ans.insert(head);
        
        vector<TreeNode*> res;
        for(auto it: ans)
        {
            res.push_back(it);
        }
        return res;
    }
};