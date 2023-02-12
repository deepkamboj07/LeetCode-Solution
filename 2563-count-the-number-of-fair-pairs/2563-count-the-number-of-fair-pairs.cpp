class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        int i=0,j=nums.size()-1;
        long long ans=0;
        while(i<n-1)
        {
            int x=lower-nums[i];
            int y=upper-nums[i];
            auto low=lower_bound(nums.begin()+i+1,nums.end(),x);
            auto hig=upper_bound(nums.begin()+i+1,nums.end(),y);
            ans+=(hig-low);
            i++;
        }
        return ans;
    }
};