class Solution {
public:
    bool dfs(int node,int color, unordered_map<int,vector<int>> &adj, vector<int>&vis)
    {
        vis[node]=color;
        for(auto v: adj[node])
        {
            if(vis[v]==-1)
            {
                dfs(v,1-color,adj,vis);
            }
            else if(vis[v] == vis[node]) return false;
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int,vector<int>> adj;
        for(auto it: dislikes)
        {
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> color(n+1,-1);
        for(int i=1;i<=n;i++)
        {
            if(color[i]==-1)
            {
                if(!dfs(i,1,adj,color))return false;
            }
        }
        
       return true;
    }
};