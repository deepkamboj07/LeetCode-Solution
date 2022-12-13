class Solution {
public:
    vector<vector<int>> dp;
    int solve(int r,int c, int n, int col, vector<vector<int>>& grid)
    {
        if(r==n-1 and c>=0 and col<n) return grid[r][c];
        if(r>=n or c>=n or c<0 or c==col)return 1e9;
        
        if(dp[r][c]!=-1)return dp[r][c];
        int sum=1e9;
        for(int k=0;k<n;k++)
        {
            if(k==c)continue;
            sum=min(sum, grid[r][c]+ solve(r+1,k,n,col,grid));
        }
        
        return dp[r][c]=sum;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int ans=1e9;
        
        dp=vector(n+1,vector<int>(n+1,-1));
        for(int i=0;i<n;i++)
        {
            int tmp=solve(0,i,n,-1e9,grid);
            ans=min(ans,tmp);
        }
        
        return ans;
    }
};