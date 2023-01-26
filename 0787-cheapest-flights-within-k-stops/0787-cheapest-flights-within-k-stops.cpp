class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flight, int src, int dst, int k) {
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
        unordered_map<int,vector<pair<int,int>>> adj;
        
        for(int i=0;i<flight.size();i++)
        {
            int u=flight[i][0];
            int v=flight[i][1];
            int w=flight[i][2];
            adj[u].push_back({v,w});
        }
        vector<int> dist(n,1e9);
        vector<int> stops(n,1e9);
        dist[src]=0;
        stops[src]=0;
        
        
        pq.push({0,src,0});
        while(!pq.empty())
        {
                auto [node_dist,node_prev,stop]=pq.top();pq.pop();
                if(node_prev==dst)return node_dist;
                if(stop>k)continue;
                

                for(auto it: adj[node_prev])
                {
                    int v=it.first;
                    int w=it.second;
                    if(dist[v] > w+node_dist || stop<=stops[v])
                    {
                        dist[v]=w+node_dist;
                        pq.push({dist[v],v,stop+1});
                        stops[v]=stop;
                    }
                }            
        }
        
        if(dist[dst]!=1e9)return dist[dst];
      //  cout<<dist[dst];
        return -1;
    }
};