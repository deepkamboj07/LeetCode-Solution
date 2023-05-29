class Solution {
public:
    int solve(int ind, string &str, unordered_set<string>&st,vector<int>&dp)
    {
        if(ind==str.size())return 0;
        if(dp[ind]!=-1)return dp[ind];
        string cur="";
        int ans=str.size();
        for(int i=ind;i<str.size();i++)
        {
            cur+=str[i];
            int curextra=cur.size();
            if(st.find(cur)!=st.end())
            {
                curextra=0;
            }
            int nextext=solve(i+1,str,st,dp);
            int total=curextra+nextext;
            
            ans=min(ans,total);
        }
        return dp[ind]=ans;
    }
    int minExtraChar(string s, vector<string>& dict) {
        unordered_set<string> st(dict.begin(),dict.end());
        vector<int> dp(s.size(),-1);
        return solve(0,s,st,dp);
    }
};