//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/*
// node structure:

struct Node
{
    int data;
    Node* left;
    Node* right;
};

*/



class Solution{

    public:
    unordered_map<Node*,Node*> parent;
    Node* target=NULL;
    void dfs(Node* root, Node* p,int k)
    {
        if(!root)return;
        if(root->data==k)
        {
            target=root;
        }
        parent[root]=p;
        dfs(root->left,root,k);
        dfs(root->right,root,k);
    }
    int ladoos(Node* root, int home, int k)
    {
        // Your code goes here
        dfs(root,NULL,home);
        
        queue<Node*> q;
        q.push(target);
        int sum=0;
        unordered_map<Node*,bool> vis;

        while(!q.empty() and k>=0)
        {
            int s=q.size();
            while(s--)
            {
                Node* top=q.front();
                vis[top]=true;
                q.pop();
                sum+=top->data;
                //cout<<top->data<<" ";
                
                if(top->left and vis.find(top->left)==vis.end())q.push(top->left);
                if(top->right and vis.find(top->right)==vis.end())q.push(top->right);
                if(parent.find(top)!=parent.end() and parent[top]!=NULL and vis.find(parent[top])==vis.end())
                {
                    q.push(parent[top]);
                }
            }
            k--;
        }
        
        return sum;
    }

};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    getchar();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        
        int home,k;
        cin>> home >> k;
        getchar();
        Solution obj;
        cout<< obj.ladoos(root,home,k) << endl;
    }
	return 0;
}


// } Driver Code Ends