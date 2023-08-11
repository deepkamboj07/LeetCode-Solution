class Solution {
public:
    
    int solve(int n, vector<int>& coins, int amt, vector<vector<int>> &dp)
    {     
        if(amt==0)return 1;
        if(n<0)
        {
            if(amt==0)return 1;
            return 0;
        }
        if(dp[n][amt]!=-1)return dp[n][amt];
        int pick=0;
        if(coins[n]<=amt)
            pick=solve(n,coins,amt-coins[n],dp);
        
        int non=solve(n-1,coins,amt,dp);
        
        return dp[n][amt]=pick+non;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return solve(n-1,coins,amount,dp);
    }
};