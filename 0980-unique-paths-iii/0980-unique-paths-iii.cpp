class Solution {
public:
    int solve(int r, int c, pair<int,int>finish, int n, int m,vector<vector<int>>& grid, int total, int step)
    {
        if(r>=n or c>=m or r<0 or c<0 or grid[r][c]==-2 or grid[r][c]==-1)
            return 0;
        
        if(r==finish.first and c==finish.second)
        {
            if(step+1==total)
            {
                return 1;
            }
            return 0;
        }
        
        int s=grid[r][c];
        grid[r][c]=-2;
        
        int ans=solve(r+1,c,finish,n,m,grid,total,step+1) + solve(r,c+1,finish,n,m,grid,total,step+1) + solve(r-1,c,finish,n,m,grid,total,step+1) + solve(r,c-1,finish,n,m,grid,total,step+1);
        
        grid[r][c]=s;
        return ans;      
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int  n=grid.size();
        int m=grid[0].size();
        
        pair<int,int> start,finish;
        int total=n*m;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    start.first=i;
                    start.second=j;
                }
                else if(grid[i][j]==2)
                {
                    finish.first=i;
                    finish.second=j;
                }
                else if(grid[i][j]==-1)
                {
                    total--;
                }
            }
        }
        
        return solve(start.first, start.second, finish, n, m, grid, total, 0);
        
    }
};