class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        int c=0;
        for(int i=0;i<n;i++)
        {
            int low=0;
            int high=m-1;
            int neg=0;
            while(low<=high)
            {
                int mid=(low+high)>>1;
                if(grid[i][mid]>=0)
                {
                    low=mid+1;
                }
                else
                {
                    neg=(m-mid);
                    high=mid-1;
                }
            }
           cout<<neg<<" ";
            c+=neg;
        }
        cout<<endl;
        
        return c;
        
    }
};