class Solution {
public:
    int maxi=-1;
    void isCycle(int node, unordered_map<int,vector<int>> &graph, vector<bool>&vis, vector<bool>&dvis,int count, vector<int>&coun)
    {
        vis[node]=true;
        dvis[node]=true;
        
        for(auto v: graph[node])
        {
            if(!vis[v])
            {
                count++;
                coun[v]=count;
                isCycle(v,graph,vis,dvis,count,coun);
            }
            else if(dvis[v])
            {
                 count++;
                 coun[v]=count-coun[v];
                 maxi=max(maxi,coun[v]);
                 break;
            }
        }
        dvis[node]=false;
    }
    int longestCycle(vector<int>& edges) {
        unordered_map<int,vector<int>> gp;
        int n=edges.size();
        for(int i=0;i<n;i++)
        {
            if(edges[i]!=-1)
            {
                gp[i].push_back(edges[i]);
            }
        }
        
        maxi=-1;
        vector<bool> vis(n,false);
        vector<bool> dvis(n,false);
        vector<int> count(n+1,0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                int node=0;
                isCycle(i,gp,vis,dvis,node,count);
            }
        }
        
        return maxi;
    }
};