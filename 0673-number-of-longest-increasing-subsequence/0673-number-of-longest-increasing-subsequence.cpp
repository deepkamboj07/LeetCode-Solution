class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1),cn(n,1);
        int len=0;
        for(int i=0;i<n;i++)
        {
            for(int prev=0;prev<i;prev++)
            {
                if(nums[i]>nums[prev] and dp[i]<1+dp[prev])
                {
                    dp[i]=1+dp[prev];
                    cn[i]=cn[prev];
                }
                else if(nums[i]>nums[prev] and dp[i]==1+dp[prev])
                {
                    cn[i]+=cn[prev];
                }
            }
            len=max(dp[i],len);
        }
        
        int num=0;
        for(int i=0;i<n;i++)
        {
            if(len==dp[i])num+=cn[i];
        }
        return num;
    }
};