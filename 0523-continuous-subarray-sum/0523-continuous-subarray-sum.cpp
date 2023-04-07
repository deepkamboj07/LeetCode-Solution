class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum=0;
        for(auto i: nums)
            sum+=i;
        if(nums.size()==1) return false;
        
        if(sum%k==0 || k==1)return true;
        
        unordered_map<int,int> mp;
        sum=0;
        mp[0]=-1;
        for(int i=0;i< nums.size();i++)
        {
            sum+=nums[i];
            int rem=sum%k;

           if(mp.count(rem)>0)
           {
               if(i-mp[rem] > 1)return true;
           }
            else
            {
                mp[rem]=i;
            }
        }
        
        return false;
    }
};