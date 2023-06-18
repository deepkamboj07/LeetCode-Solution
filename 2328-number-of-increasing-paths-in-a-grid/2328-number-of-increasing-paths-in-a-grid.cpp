class Solution {
public:
    long long int mod=(int)1e9+7;
    int solve(int r, int c, int n, int m, vector<vector<int>> &grid,int prev,map<pair<int,int>,int>&mp)
    {
        if(r<0 or c<0 or r>=n or c>=m or grid[r][c]==0 or grid[r][c]<=prev)return 0;
        
        if(mp.count({r,c}))return mp[{r,c}];
        
        int cur=grid[r][c];
        long long int ans=0;
        grid[r][c]=0;
        
        ans=(1+(solve(r+1,c,n,m,grid,cur,mp)%mod+solve(r,c+1,n,m,grid,cur,mp)%mod+
            solve(r-1,c,n,m,grid,cur,mp)%mod+solve(r,c-1,n,m,grid,cur,mp)%mod)%mod)%mod;
        
        grid[r][c]=cur;
        
        return mp[{r,c}]=ans%mod;
        
    }
    int countPaths(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        long long int count=0;
        map<pair<int,int>,int> mp;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                count=(count%mod + solve(i,j,n,m,grid,-1,mp)%mod)%mod;
            }
        }
        return count;
    }
};