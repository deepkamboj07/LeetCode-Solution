class Solution {
public:
    vector<vector<int>> dp;
    int solve(string a, string b, int n, int m)
    {
        if(n==0 or m==0)return 0;
        
        if(dp[n][m]!=-1)return dp[n][m];
        if(a[n-1]==b[m-1])
        {
            return 1+ solve(a,b,n-1,m-1);
        }        
        return dp[n][m]=max({solve(a,b,n-1,m), solve(a,b,n,m-1)});
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        
        int n=text1.length();
        int m=text2.length();
        dp=vector(text1.length()+1,vector<int>(text2.length()+1,0));
        
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(text1[i-1]==text2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return solve(text1,text2,text1.length(), text2.length());
    }
};