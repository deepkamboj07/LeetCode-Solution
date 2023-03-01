class Solution {
public:
    int countElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i=0;
        while(i<nums.size()-1 and nums[i]==nums[i+1])
        {
            i++;
        }
        int j=nums.size()-1;
        
        while(j>1 and nums[j]==nums[j-1])
            j--;
        
        int ans=j-i-2+1;
        return (ans<=0)?0:ans;
    }
};