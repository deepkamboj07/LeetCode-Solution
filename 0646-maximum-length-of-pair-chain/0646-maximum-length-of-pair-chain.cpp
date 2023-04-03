class Solution {
public:
    int solve(int ind, int n, vector<vector<int>>& pairs, vector<int>&dp)
    {
        if(ind==n)return 0;
        
        if(dp[ind]!=-1)return dp[ind];
        int maxi=-1e9;
        for(int i=ind;i<n;i++)
        {
            int ans=1;
            if(pairs[ind][1] < pairs[i][0])
            {
                ans=1+solve(i,n,pairs,dp);
            }
            maxi=max(ans,maxi);
        }
        
        int ans=solve(ind+1,n,pairs,dp);
        
        maxi=max(maxi,ans);
        return dp[ind]=maxi;
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        int n=pairs.size();
        vector<int> dp(n+1,-1);
        return solve(0,n,pairs,dp);
    }
};