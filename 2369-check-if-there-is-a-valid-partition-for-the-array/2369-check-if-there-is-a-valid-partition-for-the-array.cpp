class Solution {
public:

    bool solve(int ind, vector<int>&nums, vector<int>&dp)
    {
        if(ind==nums.size())
        {
            return true;
        }
        else if(ind>nums.size())return false;
        
        if(dp[ind]!=-1)return dp[ind];
        
        bool a=false,b=false,c=false;

        if(ind<nums.size()-1 and nums[ind]==nums[ind+1])
        {
           a = solve(ind+2,nums,dp);
        }
        if(ind+2<nums.size())
        {
            if(nums[ind]==nums[ind+1] and  nums[ind+1] == nums[ind+2])
            {
                  b= solve(ind+3,nums,dp);
            }
                
            if(nums[ind]==nums[ind+1]-1 and nums[ind+1] == nums[ind+2]-1)
            {
                //cout<<ind<<endl;
                c=solve(ind+3,nums,dp);
            }
        }
        
        return dp[ind]=(a||b||c);
        
    }
    bool validPartition(vector<int>& nums) {
        
        vector<int> dp(nums.size(),-1);
        return solve(0,nums,dp);
    }
};