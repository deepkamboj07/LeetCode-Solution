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
    unordered_map<TreeNode*, TreeNode*> parent;
    void inorder(TreeNode* root,TreeNode* p)
    {
        if(!root)return;
        parent[root]=p;
        inorder(root->left,root);
        inorder(root->right,root);
    }
    TreeNode* findNode(TreeNode* root, int key)
    {
        if(!root)return NULL;
        if(root->val==key)
        {
            //cout<<root->val<<endl;
            return root;
        }
        
        TreeNode* left=findNode(root->left,key);
        TreeNode* right=findNode(root->right,key);
        
        if(left!=NULL)return left;
        else return right;
    }
    int amountOfTime(TreeNode* root, int start) {
        inorder(root,NULL);
        TreeNode* s=findNode(root,start);
       // cout<<s->val<<endl;
        int time=-1;
        queue<TreeNode*> q;
        unordered_map<TreeNode*,int> vis;
        if(s)
        {
            q.push(s);
            vis[s]=1;
        }
        
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                TreeNode* top=q.front();
                q.pop();
                if(top->left and vis[top->left]==0)
                {
                    q.push(top->left);
                    vis[top->left]=1;
                }
                if(top->right and vis[top->right]==0)
                {
                    q.push(top->right);
                    vis[top->right]=1;
                }
                if(parent.find(top)!=parent.end() and parent[top]!=NULL and vis[parent[top]]==0)
                {
                    q.push(parent[top]);
                    vis[parent[top]]=1;
                }
            }
            cout<<endl;
            time++;
        }
        if(time==-1)return 0;
        return time;        
    }
};