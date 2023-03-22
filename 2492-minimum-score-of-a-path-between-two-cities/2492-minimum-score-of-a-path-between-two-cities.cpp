class Solution {
public:
    int ans=1e9;
    void solve(int node,unordered_map<int,vector<pair<int,int>>> &gp, vector<bool>&vis)
    {
        if(vis[node])return;
        vis[node]=true;
        
        for(auto v: gp[node])
        {
            solve(v.first,gp,vis);
            ans=min(ans,v.second);
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<pair<int,int>>> gp;
        for(auto it: roads)
        {
            int u=it[0]-1;
            int v=it[1]-1;
            int w=it[2];
            gp[u].push_back({v,w});
            gp[v].push_back({u,w});
        }
        
        vector<bool> vis(n,false);
        
        solve(0,gp,vis);

        if(vis[n-1]) return ans;
        return -1;
    }
};