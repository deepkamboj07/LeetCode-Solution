class Solution {
public:
    long long int mod=(int)1e9+7;
    long long int count(int len, int one, int zero, int n,vector<long long> &dp)
    {
        if(n==0)return 1;
        
        if(n<0)return 0;
        
        if(dp[n]!=-1)return dp[n];
        
        else return dp[n]=((count(len,one,zero,n-one,dp))%mod+count(len,one,zero,n-zero,dp)%mod)%mod;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        
        int ans=0;
        vector<long long> dp(high+1,-1);
        for(int i=low;i<=high;i++)
        {
            ans=ans%mod+ count(0,one,zero,i,dp)%mod;
        }
        return ans%mod;
    }
};