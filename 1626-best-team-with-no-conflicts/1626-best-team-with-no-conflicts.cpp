class Solution {
public:
    int solve(int ind, vector<pair<int,int>>&arr, int n,int prev, vector<vector<int>> &dp)
    {
        if(ind==n)return 0;
        
        if(dp[ind][prev]!=-1)return dp[ind][prev];
        
        int take=0;
        
        if(arr[ind].second >= prev)
            take+=(arr[ind].first + solve(ind+1, arr, n, arr[ind].second,dp));
        
        int notake=solve(ind+1,arr,n,prev,dp);
        
        return dp[ind][prev]=max(take,notake);
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>> v;
        
        int n=scores.size();
        int maxi=-1;
        for(int i=0;i<n;i++)
        {
            v.push_back({scores[i],ages[i]});
            maxi=max(maxi, ages[i]);
        }
        
        sort(v.begin(), v.end());
        
        vector<vector<int>> dp(n+1,vector<int>(maxi+1,-1));
        return solve(0,v,n,0,dp);
    }
};