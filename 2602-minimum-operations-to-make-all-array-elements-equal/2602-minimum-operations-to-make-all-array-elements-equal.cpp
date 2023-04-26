class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        int n=nums.size();
        vector<long long int> pref(n),suf(n);
        
        sort(nums.begin(), nums.end());
        
        pref[0]=nums[0];suf[n-1]=nums[n-1];
        for(int i=1;i<n;i++)
            pref[i]=pref[i-1]+nums[i];
        
        for(int i=n-2;i>=0;i--)
            suf[i]=suf[i+1]+nums[i];
        
        
        vector<long long> ans;
        for(auto q: queries)
        {
            long long int ind=upper_bound(nums.begin(), nums.end(), q) - nums.begin();

            
            long long right=0;
            long long left=0;
            if(ind<n)
            {
                right=(suf[ind]-((n-ind)*q));
            }
            if((ind-1)>=0)
            {
                left=((ind)*q)-pref[ind-1];
            }
            
           // cout<<ind<<" "<<right<<left<<endl;
            
            ans.push_back(left+right);
        }
        
        return ans;
        
    }
};