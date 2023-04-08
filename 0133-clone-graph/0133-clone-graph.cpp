/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node)return NULL;
        queue<Node*> q;
        q.push(node);
        unordered_map<Node*,Node*> mp;
        mp[node]=new Node(node->val,{});
        
        while(!q.empty())
        {
            Node *top=q.front();
            q.pop();
            
            for(auto n: top->neighbors)
            {
                if(mp.find(n)==mp.end())
                {
                    mp[n]=new Node(n->val,{});
                    q.push(n);
                }
                mp[top]->neighbors.push_back(mp[n]);
            }
        }
        
        return mp[node];
        
    }
};