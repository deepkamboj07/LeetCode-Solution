class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int n=mat.size();
        int m=mat[0].size();

        map<int,vector<int>> mp;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                mp[i+j].push_back(mat[i][j]);
            }
        }
        
        for(auto it: mp)
        {
            if(it.first%2==0)
            {
                for(int i=it.second.size()-1; i>=0 ;i--)
                {
                    ans.push_back(it.second[i]);
                }
            }
            else
            {
                for(int i=0; i<it.second.size() ;i++)
                {
                    ans.push_back(it.second[i]);
                }
            }
        }
        
        return ans;
    }
};