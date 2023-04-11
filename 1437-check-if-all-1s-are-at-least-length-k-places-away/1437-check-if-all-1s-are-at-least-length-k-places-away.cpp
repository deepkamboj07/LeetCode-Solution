class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int count=0;
        int n=nums.size();
        int j=-1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)
            {
                if(i-j-1 < k and j!=-1)
                {
                    return false;
                }
                j=i;
            }
        }
        
        return true;
    }
};