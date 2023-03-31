class Solution {
public:
    long long int mod=(int)1e9+7;
    bool isHaveApple(vector<string>& pizza,int i, int j,int n, int m)
    {
        for(int ii=i;ii<n;ii++)
        {
            for(int jj=j;jj<m;jj++)
            {
                if(pizza[ii][jj]=='A')return true;
            }
        }
        return false;
    }
    int solve(int r,int c, int n, int m, int &k,vector<string>& pizza,int user, vector<vector<vector<int>>> &dp)
    {
        if(user==k-1)
        {
            return 1;
        }
        
        if(dp[r][c][user]!=-1)return dp[r][c][user];
        
        long long int total=0;
        
        for(int i=r;i<n-1;i++)
        {
            int v1=isHaveApple(pizza,r,c,i+1,m);
            int v2=isHaveApple(pizza,i+1,c,n,m);
            
            if(v1 and v2)
            {
                long long int tmp=solve(i+1,c,n,m,k,pizza,user+1,dp)%mod;
                total=(total%mod + tmp%mod)%mod;
            }
        }
        
        for(int i=c;i<m-1;i++)
        {
            int v1=isHaveApple(pizza,r,c,n,i+1);
            int v2=isHaveApple(pizza,r,i+1,n,m);
            
            if(v1 and v2)
            {
                long long int tmp=solve(r,i+1,n,m,k,pizza,user+1,dp)%mod;
                total=(total%mod + tmp%mod)%mod;
            }
        }
        
        
        return dp[r][c][user]=total;
    }
    int ways(vector<string>& pizza, int k) {
        
        int n=pizza.size();
        int m=pizza[0].size();
        int user=0;
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(k,-1)));
        int original= solve(0,0,n,m,k,pizza,user,dp);
        return (original);
    }
};