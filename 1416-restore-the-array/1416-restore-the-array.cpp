class Solution {
public:
    int mod=1e9+7;
    int solve(int ind,string &s, int k, vector<int>&dp)
    {
        if(ind==s.size())return 1;
        
        if(dp[ind]!=-1)return dp[ind];
        
        long long int cur=0,sum=0;
        for(int i=ind;i<s.size();i++)
        {
            int digit=s[i]-'0';
            cur=(cur*10)+digit;
            
            if(cur<1 || cur>k)break;
            
            sum=(sum%mod + solve(i+1,s,k,dp)%mod)%mod;
        }
        
        return dp[ind]=sum;
    }
    int numberOfArrays(string s, int k) {
        
        vector<int> dp(s.size()+1,-1);
        return solve(0,s,k,dp);
    }
};