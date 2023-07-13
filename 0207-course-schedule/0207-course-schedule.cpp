class Solution {
public:
    bool dfs(int node,unordered_map<int,vector<int>> &ad, vector<bool>&vis,int par, vector<bool> &df)
    {
        vis[node]=true;
        df[node]=true;
        for(auto it:ad[node])
        {
            if(!vis[it]){
                if(dfs(it,ad,vis,node,df))return true;
            }
            else if(df[it]) return true;
        }
        df[node]=false;
        return false;
    }
    bool canFinish(int num, vector<vector<int>>& r) {
        unordered_map<int,vector<int>> ad;
        for(auto it:r)
        {
            ad[it[1]].push_back(it[0]);
        }
        
        vector<bool> vis(num,false);
        vector<bool> df(num,false);
        for(int i=0;i<num;i++)
        {
            if(!vis[i]){
              if(dfs(i,ad,vis,-1,df)) return false;
            }
        }
        return true;
    }
};