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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long>>q;
        bool flag=false;
        int ans=-1;
        
        q.push({root,0});
        while(!q.empty())
        {
            int s=q.size();
            int lastnode=0;
            int firstnode=0;
            int i=0;
            long long min=q.front().second;
            while(i<s)
            {
                TreeNode* top=q.front().first;
                long long id=q.front().second-min;
                q.pop();
                
                if(i==0)firstnode=id;
                if(i==s-1)lastnode=id;
                if(top->left)
                {
                    q.push({
                        top->left,
                        id*2+1
                    });
                }    
                if(top->right)
                {
                    q.push({
                        top->right,
                        id*2+2
                    });
                }
                i++;
            }
            
            ans=max(ans,(lastnode-firstnode)+1);
        }
        
        return ans;
    }
};