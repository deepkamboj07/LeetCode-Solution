class Solution {
public:
    vector<vector<int>> ans;
    void dfs(int s, vector<vector<int>>& graph, vector<int>&ds, int tar)
    {
        ds.push_back(s);
        if(s==tar)
        {
            ans.push_back(ds);
        }
        for(auto it:graph[s])
        {
                dfs(it,graph,ds,tar);
        }
        ds.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int s=0;
        int tar=graph.size()-1;
        vector<int> ds;
        dfs(s,graph,ds,tar);
        return ans;
    }
};