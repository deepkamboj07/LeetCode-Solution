class Solution {
public:
    int solve(vector<int>& costs, int n, int coins, vector<vector<int>> &dp)
    {
        if(n==0)return 0;
        if(coins<=0)return 0;
        
        if(dp[n][coins]!=-1)return dp[n][coins];
        
        if(costs[n-1]<= coins)
        {
            return dp[n][coins]= max(solve(costs,n-1,coins,dp), 1+solve(costs,n-1,coins-costs[n-1],dp));
        }
        return dp[n][coins]=solve(costs,n-1,coins,dp);
    }
    int maxIceCream(vector<int>& costs, int coins) {
        
        sort(costs.begin(), costs.end());
        int count=0;
        for(auto c: costs)
        {
            if(coins<=0)break;
            if(c<=coins)
            {
                coins-=c;
                count++;
            }
        }
        return count;
    }
};