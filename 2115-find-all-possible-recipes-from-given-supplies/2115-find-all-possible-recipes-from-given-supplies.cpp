class Solution {
public:
    unordered_map<string,bool> marked,vis;
    bool dfs(string node,  unordered_map<string,vector<string>> &adj)
    {
        if(vis[node])return marked[node];
        vis[node]=true;
        if(marked.find(node)!=marked.end())
        {
            if(marked[node])return true;
        }
        
        if(adj.find(node)==adj.end())
        {
            return marked[node]=false;
        }

        for(auto v: adj[node])
        {
            if(!dfs(v,adj))return false;
        }

        return marked[node]=true;
    }
    
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        
        unordered_map<string,vector<string>> adj;
        for(auto it: supplies)
        {
            marked[it]=true;
        }
        
        int n=recipes.size();
        
        for(int i=0;i<n;i++)
        {
            string u=recipes[i];
            for(auto v: ingredients[i])
            {
                adj[u].push_back(v);
            }
        }
        
        vector<string> ans;
        for(auto f: recipes)
        {
            if(dfs(f,adj))
            {
                ans.push_back(f);
            }               
        }
        
        return ans;
    }
};