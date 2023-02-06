class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int low=0;
        int high=nums.size()-1;
        return binary_search(nums,low,high,target);
        
    }
    
    int binary_search(vector<int> &nums ,int low, int high, int x)
    {
        int mid=(low+high)/2;
        if(nums[mid]==x) return mid;
        if(low==high) return -1;
        else if(nums[mid]>x) return binary_search(nums,low,mid,x);
        else return binary_search(nums,mid+1,high,x);
            
    }
};