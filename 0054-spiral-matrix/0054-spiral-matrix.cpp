class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        
        int sr=0,er=n-1;
        int sc=0,ec=m-1;
        
        vector<int> ans;
        int count=0;
        int total=m*n;
        while(sr<=er and sc<=ec)
        {
            for(int i=sc;i<=ec;i++)
            {
                ans.push_back(mat[sc][i]);
                count++;
            }
            sr++;
            if(count==total)break;
            
            for(int i=sr;i<=er;i++)
            {
                ans.push_back(mat[i][ec]);
                count++;
            }
            ec--;
            if(count==total)break;
            
            for(int i=ec;i>=sc;i--)
            {
                ans.push_back(mat[er][i]);
                count++;
            }
            er--;
            if(count==total)break;
            
            for(int i=er;i>=sr;i--)
            {
                ans.push_back(mat[i][sc]);
                count++;
            }
            sc++;
            if(count==total)break;
        }
        return ans;
    }
};