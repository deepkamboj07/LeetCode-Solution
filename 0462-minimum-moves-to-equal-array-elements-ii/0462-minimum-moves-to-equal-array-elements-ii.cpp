class Solution {
public:
    int operation(int num,int ind, vector<long long int>pref, vector<long long int> suf)
    {
        int left=0;
        int right=0;
        if(ind-1>=0)
        {
            left=(ind*num)-pref[ind-1];
        }
        
        if(ind+1 < pref.size())
        {
            right=suf[ind+1]-(pref.size()-(ind+1))*num;
        }
        return left+right;
    }
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return 0;
        vector<long long int> pref(n),suf(n);
        
        sort(nums.begin(), nums.end());
        
        pref[0]=nums[0];suf[n-1]=nums[n-1];
        for(int i=1;i<n;i++)
            pref[i]=pref[i-1]+nums[i];
        
        for(int i=n-2;i>=0;i--)
            suf[i]=suf[i+1]+nums[i];
        
        bool even=false;
        if(n%2==0)even=true;
        
        int mid=(n/2);
        int ans=operation(nums[mid],mid,pref,suf);
        if(even)
        {
            ans=min(ans, operation(nums[mid-1],mid-1,pref,suf));
        }

        return ans;
    }
};