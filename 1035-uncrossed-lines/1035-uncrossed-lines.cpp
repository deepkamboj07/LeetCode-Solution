class Solution {
public:
    int solve(int i, int j, vector<int>& nums1, vector<int>& nums2, vector<vector<int>> &dp)
    {
        if(i>=nums1.size() or j>=nums2.size())return 0;
        
        if(dp[i][j]!=-1)return dp[i][j];
        int maxi=0;
        
        if(nums1[i]==nums2[j])
        {
            maxi=1+solve(i+1,j+1,nums1,nums2,dp);
        }
        else
        {
            maxi=max(solve(i+1,j,nums1,nums2,dp), solve(i,j+1,nums1,nums2,dp));
        }
        
        return dp[i][j]=maxi;
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        
        vector<vector<int>> dp(nums1.size(),vector<int>(nums2.size(),-1));        
        return solve(0,0,nums1,nums2,dp);
    }
};