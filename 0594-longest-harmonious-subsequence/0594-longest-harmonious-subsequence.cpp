class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0,j=1;
        int n=nums.size();
        int ans=0;
        while(j<n)
        {
            while(nums[j]-nums[i] > 1)
            {
                i++;
            }
            if(nums[j]-nums[i]==1)
            {
                ans=max(ans,(j-i+1));
            }
            
            j++;
        }
        
        return ans;
    }
};