class Solution {
public:
    int time[3]={1,7,30};
    int calculateTime(int ind, vector<int>&days, int dayInd)
    {
        int target=days[dayInd]+time[ind]-1;
        for(int i=dayInd+1;i<days.size();i++)
        {
            if(days[i]>target)return i;
        }
        return days.size();
    }
    int solve(int ind,int n,vector<int>& days, vector<int>& costs,vector<vector<int>> &dp)
    {
        if(ind==n)
        {
            return 0;
        }
        if(dp[ind][0]!=-1)return dp[ind][0];
        int mini=1e9;
        for(int i=0;i<3;i++)
        {
            int cost=costs[i];
            int id=calculateTime(i,days,ind);
            mini=min(mini, cost+solve(id,n,days,costs,dp));
            dp[ind][0]=mini;
        }
        
        return dp[ind][0];
        
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int  n=days.size();
        vector<vector<int>> dp(n,vector<int>(3,-1));
        return solve(0,n,days,costs,dp);
    }
};