class Solution {
public:
    bool dfs(int node,unordered_map<int,vector<int>> &gp, vector<bool>&vis, vector<int>&color)
    {
        vis[node]=true;
        for(auto v: gp[node])
        {
            if(!vis[v])
            {
                color[v]=!color[node];
                if(!dfs(v,gp,vis,color))return false;
            }
            else if(color[v]==color[node])return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        unordered_map<int,vector<int>> gp;
        int n=graph.size();
        for(int i=0;i<n;i++)
        {
            int u=i;
            for(int j=0;j<graph[i].size();j++)
            {
                gp[u].push_back(graph[i][j]);
                gp[graph[i][j]].push_back(u);
            }
        }
        
        vector<bool> vis(n,false);
        vector<int> color(n,-1);
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                color[i]=1;
                if(!dfs(i,gp,vis,color))return false;
            }
        }
        return true;
    }
};