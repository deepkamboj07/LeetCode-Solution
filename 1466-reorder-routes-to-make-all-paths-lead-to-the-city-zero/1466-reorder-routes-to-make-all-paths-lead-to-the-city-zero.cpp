class Solution {
public:
    
    int dfs(int node, unordered_map<int,vector<pair<int,int>>> &gp, vector<bool>&vis)
    {
        vis[node]=true;
        int change=0;
        for(auto it : gp[node])
        {
            if(!vis[it.first])
            {
                change+=(it.second==1)?1:0;
                change+=dfs(it.first,gp,vis);
            }
        }
        return change;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int,vector<pair<int,int>>> gp;
        for(auto it: connections)
        {
            int u=it[0];
            int v=it[1];
            gp[u].push_back({v,1});
            gp[v].push_back({u,-1});
        }
        
        vector<bool> vis(n,false);
        return dfs(0,gp,vis);
    }
};