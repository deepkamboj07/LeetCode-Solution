class Solution {
public:
    int dfs(int node,int par,vector<int> &tree, vector<int> *graph)
    {

        tree[node]=1;
        
        for(auto it: graph[node])
        {
            
            if(it==par)continue;

            tree[node]+=dfs(it,node,tree,graph);

        }
        
        return tree[node];
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {

        int n=roads.size()+1;
        vector<int> graph[n];
        
        for(auto road:roads)
        {
            graph[road[0]].push_back(road[1]);
            graph[road[1]].push_back(road[0]);
        }
      //  int n=graph.size();
        vector<bool> vis(n,false);
        vector<int> tree(n,0);
        

        dfs(0,-1,tree,graph);

        
        long long ans=0;
        for(int i=1;i<n;i++)
        {
            long long it=tree[i];
            ans+=(double)ceil(it/(seats*1.0));
            long long tmp=(double)ceil(it/(seats*1.0));
            cout<<tmp<<" ";
        }
        
        return ans;
    }
};