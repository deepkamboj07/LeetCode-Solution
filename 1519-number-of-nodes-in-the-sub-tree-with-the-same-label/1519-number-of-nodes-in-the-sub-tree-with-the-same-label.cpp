class Solution {
public:
    unordered_map<int,vector<int>> mp;
    vector<bool> visited;
    vector<int> ans;
    char solve(int node,string &label, unordered_map<char,int> &fr)
    {
        if(visited[node])return '#';
        visited[node]=true;
        int prevcount=fr[label[node]];
        fr[label[node]]++;
        for(int i: mp[node])
        {
            solve(i,label,fr);
        }
        
        ans[node]+=(fr[label[node]]-prevcount);
        
        return label[node];
        
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        
        visited.resize(n,false);
        ans.resize(n,0);
        for(auto it: edges)
        {
            int u=it[0];
            int v=it[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        
        unordered_map<char,int> fr;
        solve(0,labels,fr);
        return ans;
    }
};