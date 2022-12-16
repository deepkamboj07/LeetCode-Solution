class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp.insert({0,1});
        int n=nums.size(),sum=0,c=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            int rem=sum%k;
            
            if(rem<0)
            {
                rem+=k;
            }
            
            if(mp[rem])
                c+=mp[rem];
            
            
            mp[rem]++;
        }
        
        return c;
    }
};