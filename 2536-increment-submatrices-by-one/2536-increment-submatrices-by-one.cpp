class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> mat(n,vector<int>(n,0));
        
        for(auto it: queries)
        {
            int r1=it[0], r2=it[2];
            int c1=it[1], c2=it[3];
            
            for(int i=r1; i<=r2;i++)
            {
                mat[i][c1]++;
                if(1+c2 < n)mat[i][1+c2]--;
            }
        }
        
        
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<n;j++)
            {
                mat[i][j]+=mat[i][j-1];
            }
        }
        
        return mat;
    }
};