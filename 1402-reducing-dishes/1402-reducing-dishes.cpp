class Solution {
public:
    int solve(int ind,vector<int>&satisfaction,int time,vector<vector<int>> &dp)
    {
        if(ind>=satisfaction.size())
        {
            return 0;
        }
        
       if(dp[ind][time]!=INT_MIN)return dp[ind][time];
        
        int p1=(satisfaction[ind] * time) + solve(ind+1,satisfaction,time+1,dp);
        int p2=(satisfaction[ind] * time) + solve(ind+2,satisfaction,time+1,dp);
        int p3=solve(ind+1,satisfaction,time,dp);
        
        return dp[ind][time]=max({p1,p2,p3});
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        vector<vector<int>> dp(satisfaction.size()+1,vector<int>(1e5,INT_MIN));
        return solve(0,satisfaction,1,dp);
    }
};