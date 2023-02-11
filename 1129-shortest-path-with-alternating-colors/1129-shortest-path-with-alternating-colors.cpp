class Solution {
public:
    vector<int> dijikistraVariation(unordered_map<int,vector<pair<int,int>>> &adj, int n)
    {
        vector<bool> vis(n,false);
        priority_queue<vector<int>,vector<vector<int>>, greater<vector<int>>> pq;
        vector<int> dis1(n,1e9);
        vector<int> dis2(n,1e9);
        pq.push({0,0,0});
        pq.push({0,0,1});
        dis1[0]=0;dis2[0]=0;
        
        while(!pq.empty())
        {
            auto top=pq.top();
            pq.pop();
            int distPrev=top[0];
            int node_prev=top[1];
            int color=top[2];
            
            for(auto v: adj[node_prev])
            {
                int vertexColor=v.second;
                if(color==0 and vertexColor==1)
                {
                    if(dis1[v.first] > 1 + distPrev)
                    {
                        dis1[v.first]=1+ distPrev;
                        pq.push({dis1[v.first], v.first, 1});
                    }
                }
                else if(color==1 and vertexColor==0)
                {
                    if(dis2[v.first] > 1 + distPrev)
                    {
                        dis2[v.first]=1+ distPrev;
                        pq.push({dis2[v.first], v.first, 0});
                    }
                }
            }
        }
        
        vector<int>ans(n);
        
        for(int i = 0; i < n; i++){
            if(dis1[i] == 1e9 && dis2[i] == 1e9){
                ans[i] = -1;
            }
            else{
                ans[i] = min(dis1[i], dis2[i]);
            }
        }
        
        return ans;
    }
    vector<int> solveFun(unordered_map<int,vector<pair<int,int>>> &adj, int n)
    {
        vector<int> res;
        res=dijikistraVariation(adj,n);
        vector<int> ans(n,0);
        return res;
    }
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        
        //red=0 blue=1
        unordered_map<int,vector<pair<int,int>>> adj;
        for(auto it: redEdges)
        {
            int u=it[0];
            int v=it[1];
            adj[u].push_back({v,0});
        }
        for(auto it: blueEdges)
        {
            int u=it[0];
            int v=it[1];
            adj[u].push_back({v,1});
        }
        
        return solveFun(adj,n);
    }
};