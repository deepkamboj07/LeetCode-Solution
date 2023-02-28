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
    unordered_map<string,vector<TreeNode*>> mp;
    string solve(TreeNode *root){
        if(!root)
            return "#";

        string s="(";
        s+=to_string(root->val);
        s+=solve(root->left);
        s+=solve(root->right);
        s+=')';
        mp[s].push_back(root);
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> ans;
        solve(root);
        for(auto i:mp)
        {
            //cout<<i.first<<endl;
            if(i.second.size()>1)
                ans.push_back(i.second[0]);
        }
        return ans;
        
    }
};