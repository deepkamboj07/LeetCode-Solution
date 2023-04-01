class Solution {
public:
    
    void solve(int node,unordered_map<int,vector<int>> &adj, vector<int> &ans, unordered_map<int,bool>&vis)
    {
        ans.push_back(node);
        vis[node]=true;
        
        for(auto v: adj[node])
        {
            if(vis.find(v)==vis.end() || !vis[v])
            {
                solve(v,adj,ans,vis);
            }
        }
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int,vector<int>> adj;
        unordered_map<int,int> freq;
        for(auto it: adjacentPairs)
        {
            int u=it[0];
            int v=it[1];
            freq[u]++;
            freq[v]++;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        int src=-1;
        for(auto it: freq)
        {
            if(it.second==1){
                src=it.first;
                break;
            }
        }
        
        int n=adjacentPairs.size();
        vector<int> ans;
        unordered_map<int,bool> vis;
        cout<<src;
        solve(src,adj,ans,vis);
        return ans;
    }
};