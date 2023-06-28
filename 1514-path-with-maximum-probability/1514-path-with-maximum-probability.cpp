class Solution {
public:
    unordered_map<int,vector<pair<int,double>>> adj;
    
    double dijkistra(int n,int start, int end)
    {
        vector<double> ans(n,-1);
        ans[start]=0;
        priority_queue<pair<double,int>> pq;
        pq.push({1,start});
        
        while(!pq.empty())
        {
            auto top=pq.top();
            int u=top.second;
            double prob=top.first;        
            pq.pop();
            
            for(auto it: adj[u])
            {
                double prob2=it.second;
                int v=it.first;
                if(ans[v] < (prob2 * prob))
                {
                    ans[v]=prob2*prob;
                    pq.push({ans[v],v});
                    
                }
            }
        }
        
        for(auto it: ans)
        {
            cout<<it<<" ";
        }
        if(ans[end]==-1)return 0;
        return ans[end];
        
    }
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            double prob=succProb[i];
            
            adj[u].push_back({v,prob});
            adj[v].push_back({u,prob});
        }
        
        return dijkistra(n,start,end);
        
    }
};