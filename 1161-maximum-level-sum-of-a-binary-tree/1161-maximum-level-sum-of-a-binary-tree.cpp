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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int maxi=-1e9;
        int level=-1;
        int l=0;
        while(!q.empty())
        {
            int s=q.size();
            l++;
            int sum=0;
            while(s--)
            {
                auto top=q.front();
                q.pop();
                sum+=top->val;
                if(top->left)q.push(top->left);
                if(top->right)q.push(top->right);
            }
            
            if(maxi < sum)
            {
                maxi=sum;
                level=l;
            }
        }
        
        return level;
    }
};