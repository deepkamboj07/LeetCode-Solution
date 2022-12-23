class Solution {
public:
    int solve(int ind,vector<int>& prices, bool buy,  vector<vector<int>> &dp)
    {
        if(ind>=prices.size())return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        int profit;
        if(buy)
        {
            profit=max(-prices[ind] + solve(ind+1,prices,false,dp), solve(ind+1, prices,true,dp));
        }
        else
        {
            profit=max(prices[ind]+ solve(ind+2, prices,true,dp), solve(ind+1, prices,false,dp));
        }
        return dp[ind][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(3,-1));
        return solve(0,prices,true,dp);
    }
};