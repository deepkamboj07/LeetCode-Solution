class Solution {
public:
    int solve(int ind, int n, vector<int>&nums, vector<int>&dp)
    {
        if(ind>=n-1)return 0;
        if(nums[ind]==0)return 1e9;
        
        if(dp[ind]!=-1)return dp[ind];
        
        int mini=1e8;
        for(int i=ind+1;i<=ind+nums[ind];i++)
        {
            int ans=1+solve(i,n,nums,dp);
            mini=min(mini,ans);
        }
        return dp[ind]=mini;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,-1);
        return solve(0,n,nums,dp);
    }
};