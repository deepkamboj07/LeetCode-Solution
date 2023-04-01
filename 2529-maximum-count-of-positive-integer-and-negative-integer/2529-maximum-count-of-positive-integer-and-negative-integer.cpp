class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;
        
        while(low<=high)
        {
            int mid=(low+high)>>1;
            
            if(nums[mid]>0)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        
        int pos=nums.size()-low;
        
        low=0;
        high=nums.size()-1;
        
        while(low<=high)
        {
            int mid=(low+high)>>1;
            
            if(nums[mid]<0)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        
        int neg=low;
        return max(neg,pos);
    }
};