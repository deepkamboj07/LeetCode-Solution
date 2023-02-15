class Solution {
public:
    
    int numSubseq(vector<int>& nums, int target) {
        long long int mod=(int)1e9+7;
        sort(nums.begin(), nums.end());
        int i=0,j=(nums.size()-1);
        vector<int> pow2(j+2,1);
        for(int i=1;i<=j;i++)
        {
            pow2[i]=(pow2[i-1]*2)%mod;
        }
        long long int count=0;
        while(i<=j)
        {
            int mini=nums[i];
            int maxi=nums[j];
            if((mini+maxi) > target)j--;
            else
            {
                count=(count%mod + pow2[j-i])%mod;
                i++;
            }
        }
        return count;
    }
};