class Solution {
public:
    int solve(vector<int>&cuts, int i, int j,int n, vector<vector<int>>&dp)
    {
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=1e9;
        for(int k=i;k<=j;k++)
        {
            ans=min(ans,solve(cuts,i,k-1,n,dp)+solve(cuts,k+1,j,n,dp)+ cuts[j+1]-cuts[i-1]);
        }
        return dp[i][j]=ans;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(cuts.size()+1,vector<int>(cuts.size()+1,-1));
        return solve(cuts,1,cuts.size()-2,n,dp);
    }
};