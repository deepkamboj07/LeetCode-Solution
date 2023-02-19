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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        
        bool flag=true;
        while(!q.empty()){
            int size=q.size();
            vector<int> ds(size);
            for(int i=0;i<size;i++)
            {
                TreeNode *tmp=q.front();
                q.pop();
                
                int index=(flag==true)?i:size-1-i;
                ds[index]=tmp->val;
                
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);       
            }
            
            flag=(flag==true)?false:true;
            ans.push_back(ds);
        }
        return ans;
    }
};