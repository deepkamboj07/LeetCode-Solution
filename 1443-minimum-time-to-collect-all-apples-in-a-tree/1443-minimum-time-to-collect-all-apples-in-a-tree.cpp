class Solution {
public:
    unordered_map<int,vector<int>> adj;
    vector<bool> vis;
    
    int solve(int node, int cost, vector<bool>&hasApple)
    {
        if(vis[node])return 0;
        vis[node]=true;
        
        int childcost=0;
        
        for(int it: adj[node])
        {
            childcost+=solve(it,2,hasApple);
        }
        
        if(childcost==0 and hasApple[node]==false)return 0;
        
        return childcost+cost;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        
        vis.resize(n,false);
        for(auto it: edges)
        {
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        return solve(0,0,hasApple);
    }
};