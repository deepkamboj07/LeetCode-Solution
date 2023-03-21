class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long int ans=0;
        long long i=0,j=0;
        int n=nums.size();
        
        while(j<n)
        {
            if(nums[j]==0)
            {
                j++;
            }
            else if(i<j)
            {
                ans+=((j-i+1)*(j-i)/2);
                j++;
                i=j;
            }
            else
            {
                i++;
                j++;
            }
        }
        
        if(i<j)
        {
             ans+=((j-i+1)*(j-i)/2);
        }
        return ans;
    }
};