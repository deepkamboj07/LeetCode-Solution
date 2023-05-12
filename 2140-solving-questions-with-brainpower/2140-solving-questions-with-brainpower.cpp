class Solution {
public:
    long long solve(int ind, vector<vector<int>>& ques, vector<long long> &dp)
    {
        if(ind>=ques.size())return 0;
        
        if(dp[ind]!=-1)return dp[ind];
        
        long long take=ques[ind][0]+solve(ind+ques[ind][1]+1,ques,dp);
        long long notake=solve(ind+1,ques,dp);
        
        return dp[ind]=max(take,notake);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        
        vector<long long> dp(questions.size()+1,-1);
        return solve(0,questions,dp);
        
    }
};