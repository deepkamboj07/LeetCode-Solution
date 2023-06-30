class Solution {
public:
    
    bool check(int i,int j,vector<vector<int>>&v,int r,int c)
    {   
        if(i<0 || i>=r || j<0 || j>=c || v[i][j]==1 || v[i][j]==2)
            return 0;
        if(i==r-1)
            return 1;
        v[i][j]=2;
        bool a=check(i+1,j,v,r,c);
        bool b=check(i,j+1,v,r,c);
        bool c1=check(i-1,j,v,r,c);
        bool d=check(i,j-1,v,r,c);
        return a||b||c1||d;
    }
    
    
    bool solve(int mid, int col,int row, vector<vector<int>> &grid, vector<vector<int>>&w)
    {
            
        for(int i=0;i<mid;i++)
            grid[w[i][0]-1][w[i][1]-1]=1;
    
        for(int i=0;i<col;i++)
        {
            if(grid[0][i]==0 && check(0,i,grid,row,col))return true;
        }
        
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int ans=0;
        int n=cells.size();
        int low=0,high=n-1;
        
        
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            vector<vector<int>> grid(row,vector<int>(col,0));
                  
            if(solve(mid,col,row,grid,cells))
            {
                ans=mid;
                low=mid+1;
            }
            else high=mid-1;    
            
        }
        
        return ans;
    }
};