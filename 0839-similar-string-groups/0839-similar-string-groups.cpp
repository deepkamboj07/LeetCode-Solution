class Solution {
public:
    unordered_map<int,vector<int>> adj;
    
    bool isSimilar(string a, string b)
    {
        if(a==b)return true;
        
        int dif=0;
        for(int i=0;i<a.length();i++)
        {
            if(a[i]!=b[i])dif++;
            if(dif>2)return false;
        }
        return dif==2 || dif==0;
    }
    
    void dfs(int node, vector<bool>&vis)
    {
        vis[node]=true;
        for(auto v: adj[node])
        {
            if(!vis[v])
            {
                dfs(v,vis);
            }
        }
    }
    int numSimilarGroups(vector<string>& strs) {
        
        int n=strs.size();
        for(int i=0;i<n;i++)
        {
            string str=strs[i];
            for(int j=i+1;j<n;j++)
            {
                if(isSimilar(str,strs[j]))
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        int ans=0;
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                ans++;
                dfs(i,vis);
            }
        }
        
        return ans;
    }
};