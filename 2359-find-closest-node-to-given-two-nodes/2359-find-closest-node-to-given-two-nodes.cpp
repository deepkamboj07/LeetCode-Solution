class Solution {
public:
    unordered_map<int,vector<int>> adj;
    
    vector<int> dijikstra(int node, int n)
    {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,node});
        
        vector<int> dist(n,1e9);
        dist[node]=0;
        
        while(!pq.empty())
        {
            int u=pq.top().second;
            int prev=pq.top().first;
            pq.pop();

            for(auto v: adj[u])
            {
                if(dist[v] > prev + 1)
                {
                    dist[v]=prev+1;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        for(int i=0;i<n;i++)
        {
            if(edges[i]==-1)continue;
            int u=i;
            int v=edges[i];
            adj[u].push_back(v);
        }
        
        vector<int> distance_from_node1=dijikstra(node1, n);
        vector<int> distance_from_node2=dijikstra(node2, n);
        
//         for(auto it: distance_from_node1)
//         {
//             cout<<it<<" ";
//         }
//         cout<<endl;
        
//         for(auto it: distance_from_node2)
//         {
//             cout<<it<<" ";
//         }
        
        int node=-1,maxi=1e9;
        for(int i=0;i<n;i++)
        {
            int dist=max(distance_from_node1[i], distance_from_node2[i]);
            if(dist < maxi)
            {
                maxi=dist;
                node=i;
            }
        }
        return node;
    }
};