class Solution {
public:
    bool solve(int ind, string &s1, string &s2, string &s3,int i, int j,vector<vector<vector<int>>> &dp)
    {
        //if(i<0 and j<0 and k<0)return true;
        
        if(i==s1.size() and j==s2.size() and ind==s3.size())return true;
        else if(ind==s3.size())return false;
        
        if(i<s1.size() and j<s2.size() and dp[ind][i][j]!=-1) return dp[ind][i][j];
        
        bool a=false,b=false;
        if(s1[i]==s3[ind])
            a=solve(ind+1,s1,s2,s3,i+1,j,dp);
        if(s2[j]==s3[ind])
            b=solve(ind+1,s1,s2,s3,i,j+1,dp);
        
        return dp[ind][i][j]=a||b;
    }
    bool isInterleave(string s1, string s2, string s3) {
        
        vector<vector<vector<int>>> dp(s3.size(),vector<vector<int>>(s1.size()+1, vector<int>(s2.size()+1,-1)));
        return solve(0,s1,s2,s3,0,0,dp);
    }
};