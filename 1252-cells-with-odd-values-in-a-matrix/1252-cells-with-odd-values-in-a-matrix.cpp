class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<int> row(m,0);
        vector<int> col(n,0);
        
        for(auto it: indices)
        {
            int r=it[0];
            int c=it[1];
            row[r]++;
            col[c]++;
        }
        
        int odd=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int number=row[i]+col[j];
                if(number%2!=0)odd++;
            }
        }
        return odd;
    }
};