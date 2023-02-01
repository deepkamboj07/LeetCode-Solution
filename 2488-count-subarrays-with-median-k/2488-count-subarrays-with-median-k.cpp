class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        
        int ans=0;
        int loc=-1,n=nums.size();
       // sort(nums.begin(), nums.end());
        for(int i=0;i<n;i++)
        {
            if(nums[i]==k)
            {
                loc=i;
                break;
            }
        }
        if(loc==-1)return 0;
        
        unordered_map<int, int> mp;
        int dif=0;
        for(int i=loc+1;i<n;i++)
        {
            if(nums[i]<k)
                dif--;
            else if(nums[i]>k)
                dif++;
            
            mp[dif]++;
        }
        
        mp[0]++;
        dif=0;
        ans+=mp[1-dif];
        ans+=mp[0-dif];
        
        for(int i=loc-1;i>=0;i--)
        {
            if(nums[i]<k)
                dif--;
            else if(nums[i]>k)
                dif++;
            
            ans+=mp[1-dif];
            ans+=mp[0-dif];
        }
        
        return ans;
    }
};