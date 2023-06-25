class Solution {
public:
    int mod=1e9+7;
    int solve(vector<int>&arr, int ind, int end, int fuel, vector<vector<int>> &dp)
    {
        if(fuel<0)return 0;
        
        if(dp[ind][fuel]!=-1)return dp[ind][fuel];
        
        long long int total=(ind==end)?1:0;
        
        for(int i=0;i<arr.size();i++)
        {
            if(ind!=i and fuel>=abs(arr[ind]-arr[i]))
            {
                total=(total%mod + solve(arr,i,end,fuel-abs(arr[ind]-arr[i]),dp)%mod)%mod;
            }
        }
        
        return dp[ind][fuel]=total%mod;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
       vector<vector<int>> dp(locations.size(),vector<int>(fuel+1,-1));
       return solve(locations, start, finish, fuel,dp);
    }
};