class Solution {
public:
    long long findPair(int n)
    {
        if(n<1)return 0;
        return ((n*(n+1))/2);
    }
    long long countGood(vector<int>& nums, int k) {
        map<int,int> mp;
        int n=nums.size();
        
        int i=0,j=0;
        long long pair=0,ans=0;
        while(j<n)
        {
            int num=nums[j];
            mp[num]++;
            int count=findPair(mp[num]-1);
            if(count > 1)
            {
                pair-=findPair( (mp[num]-2) );
                pair+=count;
                
            }
            else if(count==1) pair++;
            
            while(i<=j and pair >= k)
            {
                ans+=(nums.size() - j);
                mp[nums[i]]--;
                pair-=mp[nums[i]];
                if(mp[nums[i]]==0)mp.erase(nums[i]);
                i++;
                
            }
            j++;
        }
        
        return ans;
    }
};