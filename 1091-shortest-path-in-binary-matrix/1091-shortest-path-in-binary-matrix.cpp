class Solution {
    int dir[8][2]={{-1,0},{0,1},{1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n=grid.size();
        queue<pair<pair<int,int>,int>>q;
        
        if(grid[0][0]==1 || grid[n-1][n-1]==1)return -1;
        q.push({{0,0},0});
        int ans=INT_MAX;
        int count=0;
        while(!q.empty())
        {
            auto top=q.front().first;
            int path=q.front().second;
            int i=top.first;
            int j=top.second;
            cout<<i<<" "<<j<<endl;
            q.pop();
            if(i==n-1 and j==n-1)
            {
                ans=min(ans,(path+1));
            }
            int v=grid[i][j];
            if(grid[i][j]==0)
            {
                grid[i][j]=1;
                for(int k=0;k<8;k++)
                {
                    int x=i+dir[k][0];
                    int y=j+dir[k][1];
                    
                    if(x>=0 and x<n and y>=0 and y<n)
                    {
                        if(grid[x][y]==0)q.push({{x,y},(path+1)});
                    }
                }
            }
            count++;
        }
        
        return (ans==INT_MAX)?-1:ans;
        
    }
};