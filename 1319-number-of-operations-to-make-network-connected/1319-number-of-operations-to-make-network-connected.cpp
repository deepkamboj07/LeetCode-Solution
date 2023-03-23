class Solution {
private:
    vector<int> parent;
    vector<int> rank;
    int findParent(int node)
    {
        if(node==parent[node])
            return node;
        return parent[node]=findParent(parent[node]);
    }
    
    void makeparent(int u, int v)
    {
        u=findParent(u);
        v=findParent(v);
        
        if(rank[u]>rank[v])
        {
            parent[v]=u;
        }
        else if(rank[u]<rank[v])
            parent[u]=v;
        else
        {
            parent[v]=u;
            rank[u]++;
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()< n-1)return -1;
        for(int i=0;i<n;i++)
        {
            parent.push_back(i);
            rank.push_back(-1);
        }
        
        int ans=0;
        for(auto it: connections)
        {
            int u=it[0];
            int v=it[1];
            makeparent(u,v);
        }
        
        for(int i=0;i<n;i++)
        {
            if(parent[i]==i)ans++;
        }

        return ans-1;
    }
};