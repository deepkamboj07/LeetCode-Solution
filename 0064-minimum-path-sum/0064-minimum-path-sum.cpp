class Solution {
public:
    void solve(int row, int col, int m, int n, vector<vector<int>>&grid, int &ans, int sum)
    {
        if(row==m-1 and col==n-1)
        {
            sum+=grid[row][col];
            ans=min(ans,sum);
            return;
        }
        if(row==m or col==n)
            return;
        
        solve(row+1,col,m,n,grid,ans,sum+grid[row][col]);
        solve(row,col+1,m,n,grid,ans,sum+grid[row][col]);
        
    }
    
    int solve2(int row, int col, int m, int n,vector<vector<int>>&grid, vector<vector<int>>&dp)
    {
        if(row==m-1 and col==n-1)
            return grid[row][col];
        
        if(row>=m or col>=n)
            return 1e9;
        if(dp[row][col]!=-1)
            return dp[row][col];
        
        int down=grid[row][col]+solve2(row+1,col,m,n,grid,dp);
        int right=grid[row][col]+solve2(row,col+1,m,n,grid,dp);
        
        return dp[row][col]=min(down,right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=INT_MAX;
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve2(0,0,m,n,grid,dp);
        //return ans;
    }
};