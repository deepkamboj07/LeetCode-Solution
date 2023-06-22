class Solution {
public:
    int solve(int ind, vector<int>& prices, bool buy, int fee, vector<vector<int>> &dp)
    {
        if(ind==prices.size())return 0;    
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        int profit;
        if(buy)
        {
            profit=max(-prices[ind]+ solve(ind+1, prices, false, fee,dp), solve(ind+1,prices,true,fee,dp));
        }
        else
        {
            profit=max(prices[ind] - fee +solve(ind+1, prices, true, fee,dp), solve(ind+1, prices,false,fee,dp));
        }
        return dp[ind][buy]=profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(0,prices,true,fee,dp);
    }
};