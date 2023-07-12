class Solution {
public:
    bool dfs(int node,vector<vector<int>>& graph,  vector<bool>&vis, vector<bool> &dvis, vector<bool>&p)
    {
        vis[node]=true;
        dvis[node]=true;
        for(auto it:graph[node])
        {
            if(!vis[it]){
                if(dfs(it,graph,vis,dvis,p))
                    return p[node]=true;
            }
            else if(dvis[it] and vis[it])
            {
                return p[node]=true;
            }
        }
        
        dvis[node]=false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<bool> vis(n+1,false);
        vector<bool> dvis(n+1,false);
        vector<bool> present(n+1,false);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
                dfs(i,graph,vis,dvis,present);
        }
        
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(!present[i])ans.push_back(i);
        }
        return ans;
    }
};