/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void makeParent(unordered_map<TreeNode*,TreeNode*> &mp, TreeNode* root)
    {
        if(root==NULL)return;
        
        if(root->left)mp[root->left]=root;
        makeParent(mp,root->left);
        
        if(root->right)mp[root->right]=root;
        makeParent(mp,root->right);
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(root==NULL)return {};
        unordered_map<TreeNode*,TreeNode*> mp;
        unordered_map<TreeNode*, bool> visited;
        mp[root]=NULL;
        makeParent(mp,root);
        
        queue<TreeNode*> q;
        q.push(target);
        visited[target]=true;
        vector<int> ans;
        
        while(!q.empty() and k--)
        {
            int s=q.size();
            while(s--)
            {
                TreeNode* top=q.front();
                q.pop();
                if(top->left and !visited[top->left])
                {
                    q.push(top->left);
                    visited[top->left]=true;
                    
                }
                if(top->right and !visited[top->right]){
                    q.push(top->right);
                    visited[top->right]=true;
                }
                
                if(mp[top] and visited[mp[top]]!=true)
                {
                        q.push(mp[top]);
                        visited[mp[top]]=true;
                }
                
            }
        }
        
        while(!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};