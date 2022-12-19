class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        queue<int> q;
        q.push(source);
        vector<bool> vis(n+1,false);
        vis[source]=true;
        
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            //cout<<u<<endl;
            for(auto v:mp[u])
            {
                if(!vis[v])
                {
                    q.push(v);
                    vis[v]=true;
                }
            }
        }
        
        return vis[destination];
    }
};