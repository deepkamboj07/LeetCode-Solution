class Solution {
public:
    int solve(vector<int>&nums, int mid, int p, int n)
    {
        int i=0,count=0;
        
        while(i<n-1)
        {
            if(abs(nums[i]-nums[i+1]) <= mid )
            {
                count++;
                i+=2;
            }
            else i++; 
        }
        
        return count>=p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        int low=0,high=nums[n-1] - nums[0];
        int ans=0;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(solve(nums,mid,p,n))
            {
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        
        return ans;
    }
};