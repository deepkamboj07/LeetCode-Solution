class Solution {
public:
    int mod=1e9+7;
    int solve(int ind,vector<int>& group, vector<int>& profit,int p, int n,vector<vector<vector<int>>> &dp)
    {
        if(ind==group.size())
        {
            if(p==0 and n>=0) return 1;
            return 0;
        }
        if(n<0)return 0;
        if(dp[ind][n][p]!=-1) return dp[ind][n][p];
        
        int ans=solve(ind+1,group,profit,max(0,p-profit[ind]),n-group[ind],dp);
        int no=solve(ind+1,group,profit,p,n,dp);
        
        
        return dp[ind][n][p]=(ans%mod+no%mod)%mod;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        
        int s=group.size();
        vector<vector<vector<int>>> dp(s,vector<vector<int>>(n+1,vector<int>(minProfit+1,-1)));
        return solve(0,group,profit,minProfit,n,dp);
        
    }
};