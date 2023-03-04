class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int left=-1;
        int right=-1;
        int n=nums.size();
        int leftInvalid=-1;
        long long count=0;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]>=minK and nums[i]<=maxK)
            {
                left=(nums[i]==minK)?i:left;
                right=(nums[i]==maxK)?i:right;
                
                count+=max(0, (min(left,right)-leftInvalid));
            }
            else
            {
                leftInvalid=i;
                left=-1;
                right=-1;
            }
        }
        
        return count;
    }
};