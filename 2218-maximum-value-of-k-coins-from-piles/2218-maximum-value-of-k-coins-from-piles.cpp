class Solution {
public:
    
    int solve(int ind, vector<vector<int>>& piles, int k, vector<vector<int>> &dp)
    {
        if(ind==piles.size() || k<=0)
        {
            return 0;
        }
        
        if(dp[ind][k]!=-1)return dp[ind][k];
        
        int maxi=0;
        
        maxi=max(maxi, solve(ind+1,piles,k,dp));
        for(int i=0;i<k and i<piles[ind].size();i++)
        {
            int newsum=piles[ind][i]+solve(ind+1,piles,k-(i+1),dp);
            maxi=max(maxi, newsum);
        }
        
        return dp[ind][k]=maxi;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        
        int n=piles.size();
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<piles[i].size();j++)
            {
                piles[i][j]=piles[i][j-1]+piles[i][j];
            }
        }
        
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        
        return solve(0,piles,k,dp);
    }
};