class Solution {
public:
    int targetSum(vector<int>&nums, long long int target)
    {
        unordered_map<int,int> mp;
        int mini=1e9;
        int j=0,n=nums.size();
        int sum=0;
        while(j<n)
        {
            sum+=nums[j];
            if(sum==target)
            {
                mini=min(mini, (j+1));
            }
            
            if(mp.find(sum-target)!=mp.end())
            {
                mini=min(mini, (j-mp[sum-target]));
            }
            
            mp[sum]=j;
            j++;
        }
        return mini;
    }
    int minSubarray(vector<int>& nums, int p) {
        long long int sum=0;
        for(auto it: nums)
        {
            sum+=it;
        }
        
        if(sum%p==0)return 0;
        int rem=sum%p;
        int res=1e9;
        unordered_map<int, int> pre_sum;
        pre_sum[0] = -1;
        int tmp=0;
        
        for (int i = 0; i < nums.size(); i++) {
            tmp = (tmp + nums[i]) % p;
            pre_sum[tmp] = i;
            int rest = (tmp - rem + p) % p;
            
            if (pre_sum.find(rest) != pre_sum.end()) res = min(res, i - pre_sum[rest]);
        }
        return res >= nums.size() ? -1 : res;
    }
};