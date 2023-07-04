class Solution {
public:
    int singleNumber(vector<int>& nums) {
        long ans=0;
        int p=0;
        
        for(int i=0;i<32;i++)
        {
            int t=0,sum=0;
            for(int j=0;j<nums.size();j++)
            {
                t=nums[j]&1;
                nums[j]=nums[j]>>1;
                sum+=t;
            }
            sum=sum%3;
            ans=ans+ sum*pow(2,p);
            p++;
        }
        
        return ans;
    }
};