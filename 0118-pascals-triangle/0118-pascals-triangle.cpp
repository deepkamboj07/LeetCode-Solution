class Solution {
public:
    vector<vector<int>> generate(int n) {
        
        vector<vector<int>> mat(n);
        mat[0].push_back(1);
        
        if(n==1)
            return mat;
        
        int count=0;
        for(int i=1;i<n;i++)
        {
            count=mat[i-1].size()-1;
            count+=2;
            mat[i].push_back(1);
            
            for(int j=1;j<count-1;j++)
            {
                mat[i].push_back((mat[i-1][j-1] + mat[i-1][j]));
            }
            
            mat[i].push_back(1);
        }
        
        return mat;
        
    }
};