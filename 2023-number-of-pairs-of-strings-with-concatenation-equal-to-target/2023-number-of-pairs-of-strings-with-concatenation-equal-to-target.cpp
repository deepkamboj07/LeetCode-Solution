class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int n=nums.size();
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(i==j)continue;
                if(nums[i]+nums[j]==target)ans++;
                if(nums[j]+nums[i]==target)ans++;
            }
        }
        return ans;
    }
};