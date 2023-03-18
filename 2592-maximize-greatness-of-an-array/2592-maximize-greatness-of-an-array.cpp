class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i=0,j=0,n=nums.size();
        int ans=0;
        while(j<n)
        {
            if(nums[j]>nums[i]){ans++,i++;}
            j++;
        }
        
        return ans;
    }
};