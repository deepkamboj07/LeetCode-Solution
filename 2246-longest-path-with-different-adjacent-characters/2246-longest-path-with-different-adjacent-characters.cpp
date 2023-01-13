class Solution {
public:
    unordered_map<int,vector<int>> mp;
    vector<bool> vis;
    int maxi=1;
    int solve(int node, string &s)
    {
        if(vis[node])return 0;
        vis[node]=true;
        
        int path1=0,path2=0;
        for(auto i: mp[node])
        {
            int childpath=solve(i,s);
            if(s[node]!=s[i])
            {
                if(childpath > path2)path2=childpath;
                if(path2 > path1)swap(path1,path2);
            }
        }
        
        maxi=max({maxi,path1+path2+1});
        return path1+1;
    }
    int longestPath(vector<int>& parent, string s) {
        vis.resize(parent.size(),false);
        for(int i=1;i<parent.size();i++)
        {
            int u=parent[i];
            int v=i;
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        
        solve(0,s);
        return maxi;
    }
};