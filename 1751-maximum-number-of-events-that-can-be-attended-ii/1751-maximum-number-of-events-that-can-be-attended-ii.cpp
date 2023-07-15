class Solution {
public:
    int maxi=0;
    int solve(int ind,vector<vector<int>>& events, int k,int start, map<pair<int,pair<int,int>>,int>&dp)
    {
        if(k<=0)return 0;
        if(ind==events.size())
        {
            return 0;
        }
        
        if(dp.find({ind,{k,start}})!=dp.end())return dp[{ind,{k,start}}];
        int take=0;
        if(start <= events[ind][0])
        {
            take=(events[ind][2] + solve(ind+1,events,k-1,events[ind][1]+1,dp));
        }
        int notaken=solve(ind+1,events,k,start,dp);
        
        return dp[{ind,{k,start}}]= max(take,notaken);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        
        int n=events.size();
        map<pair<int,pair<int,int>>,int> dp;
        sort(events.begin(), events.end());
        return solve(0,events,k,1,dp);
    }
};