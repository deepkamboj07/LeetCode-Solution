class Solution {
public:
    int solve(vector<int>& arr, int sum,vector<int>&dp)
    {
        if(sum<0) return 0;
        if(sum==0) return 1;
        if(dp[sum]!=-1) return dp[sum];
        int res=0;
        for(int i=0;i<arr.size();i++)
            res+=solve(arr,sum-arr[i],dp);
        return dp[sum]=res;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1,-1);
        return solve(nums,target,dp);
    }
};