class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        int dir[4][2]={{1,0},{-1,0},{0,-1},{0,1}};
        queue<pair<int,int>> q;
        q.push({0,0});
        vector<vector<int>> ans(n,vector<int>(m,1e9));
        ans[0][0]=0;
        while(!q.empty())
        {
            int s=q.size();
            while(s--)
            {
                auto top=q.front();
                int x=top.first;
                int y=top.second;
                
                q.pop();

                for(int i=0;i<4;i++)
                {
                    int r=x+dir[i][0];
                    int c=y+dir[i][1];
                    
                    if(r<n and c<m and c>=0 and r>=0)
                    {
                        int diff = abs(grid[r][c] - grid[x][y]);
                        int maxval = max(ans[x][y], diff);
                        if (maxval < ans[r][c]) 
                        { 
                            ans[r][c] = maxval;
                            q.push({r,c});
                        }
                    }
                }
               // grid[x][y]=-1;
            }
        }
        return ans[n-1][m-1];
    }
};