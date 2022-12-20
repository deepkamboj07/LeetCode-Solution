class Solution {
public:
    void dfs(int node,vector<vector<int>>& rooms,vector<bool>&vis)
    {
        vis[node]=true;
        for(auto it:rooms[node])
        {
            if(!vis[it])
                dfs(it,rooms,vis);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        int m=rooms[0].size();
        vector<bool> vis(n,false);
        dfs(0,rooms,vis);
        
        for(auto check:vis)
        {
            if(check==false)return false;
        }
        return true;
    }
};