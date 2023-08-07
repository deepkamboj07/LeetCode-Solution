class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        //cout<<n<<" "<<m;
        int i=0,j=m-1;
        while(i<n and j>=0)
        {
            if(matrix[i][j]>target)
            {
                j--;
            }
            else if(matrix[i][j]<target)
            {
                i++;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};