class Solution {
public:
    
    int solve(int ind, vector<vector<int>>& books, int maxWidth, int n, vector<int>&dp)
    {
        if(ind==n)
        {
            return 0;
        }
        
        if(dp[ind]!=-1)return dp[ind];
        
        int width=0;
        int maxHeight=0;
        int mini=1e9;
        
        for(int i=ind;i<n;i++)
        {
            width+=books[i][0];
            maxHeight=max(maxHeight, books[i][1]);
            
            if(width <= maxWidth)
            {
                int tmp=solve(i+1,books,maxWidth,n,dp);
                mini=min(mini, tmp+maxHeight);
            }
        }
        return dp[ind]=mini;
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        
        int n=books.size();
        vector<int> dp(n,-1);
        return solve(0,books,shelfWidth,n,dp);
    }
};