class Solution {
public:
    void dfs(int node,unordered_map<int,vector<int>> &gp,vector<bool> &vis, unordered_map<int,int>&mark,int stamp)
    {
        mark[stamp]++;
        vis[node]=true;
        
        for(auto v: gp[node])
        {
            if(!vis[v])
            {
                dfs(v,gp,vis,mark,stamp);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> gp;
        if(edges.size()==0)
        {
            long long int t=n;
            return (long long int)((t-1)*t)/2;
        }
        for(auto it: edges)
        {
            int u=it[0];
            int v=it[1];
            gp[u].push_back(v);
            gp[v].push_back(u);
        }
        
        vector<bool> vis(n,false);
        unordered_map<int,int> mp;
        int stamp=1;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i,gp,vis,mp,stamp);
                stamp++;
            }
        }
        
        long long int ans=0;
        if(mp.size()==0 || mp.size()==1)return 0;
        
        vector<int> tmp;
        
        for(auto it: mp)
        {
            tmp.push_back(it.second);
        }
        
        n=tmp.size();
        for(int i=0;i<n;i++)
        {
            long long int t=tmp[i];
            for(int j=i+1;j<n;j++)
            {
                ans+=(t*tmp[j]);
            }
        }

        return ans;
    }
};