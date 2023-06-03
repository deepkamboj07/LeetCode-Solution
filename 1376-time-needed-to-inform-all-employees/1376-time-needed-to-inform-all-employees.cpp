class Solution {
public:
    int totaltime=0,time=0;
    void dfs(int man, vector<int>& informTime,  unordered_map<int,vector<int>> &adj)
    {
        totaltime=max(totaltime,time);
        for(auto emp:adj[man])
        {
            time+=informTime[man];
            dfs(emp,informTime,adj);
            time-=informTime[man];
        }
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int,vector<int>> adj;
        int s=0;
        for(int i=0;i<n;i++){
           if(manager[i]!=-1)adj[manager[i]].push_back(i);
           else s=i; 
        }
        
        dfs(s,informTime,adj);
        return totaltime;
    }
};