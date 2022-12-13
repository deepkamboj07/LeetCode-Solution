class Solution {
public:
    // memoization code
    int solve(int n, int c,vector<vector<int>>& mat, vector<vector<int>> &dp)
    {
        if(n<0 or c<0 or c>=mat[0].size()) return 1e9;
        if(n==0)
        {
            return mat[n][c];
        }
        if(dp[n][c]!=-1) return dp[n][c];
        
        int bottom=mat[n][c]+solve(n-1,c,mat,dp);
        int left=mat[n][c]+solve(n-1,c-1,mat,dp);
        int right=mat[n][c]+solve(n-1,c+1,mat,dp);
        
        return dp[n][c]=min({bottom, left,right});
    }
    
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n=mat.size();
        int ans=1e9;
        
        vector<int> prev(n,0);
        for(int i=0;i<n;i++)
        {
            prev[i]=mat[0][i];
        }
        
        for(int i=1;i<n;i++)
        {
            vector<int> cur(n,0);
            for(int j=0;j<n;j++)
            {
                int one=mat[i][j]+prev[j];
                int two=1e9,three=1e9;
                if(j>0)two=mat[i][j]+prev[j-1];
                if(j<n-1)three=mat[i][j]+prev[j+1];
                cur[j]=min({one,two,three});
            }
            prev=cur;
        }
        
        for(int i=0;i<n;i++)
        {
            ans=min(ans,prev[i]);
        }
        return ans;
    }
};