class Solution {
public:
    double solve(int i, int j,int p, vector<int>&nums, vector<vector<double>> &dp)
    {
        if(i==j)return nums[i];
        if(p==1)
        {
            double sum=0;
            for(int k=i;k<=j;k++)
                sum+=nums[k];
            return sum/(j-i+1);
        }
        
        if(dp[i][p]!=-1)return dp[i][p];
        double ans=-1;
        double sum=0;
        for(int k=i;k<=j;k++)
        {
            sum+=nums[k];
            double tmp=(sum)/(k-i+1);
            tmp+=solve(k+1,j,p-1,nums,dp);
            
            ans=max(ans,tmp);
        }
        return dp[i][p]=ans;
    }
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<double>> dp=vector(n+1,vector<double>(k+1,-1));
        return solve(0,n-1,k,nums,dp);
    }
};