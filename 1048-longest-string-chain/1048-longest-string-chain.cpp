class Solution {
public:
    bool isCorrect(string &s1, string &s2)
    {
        if(s1.size()!=s2.size()+1)return false;
        
        int i=0,j=0;
        while(i<s1.size())
        {
            if(j<s2.size() and s1[i]==s2[j])
            {
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }
        
        if(i==s1.size() and j==s2.size()) return true;
        else return false;
    }
    static bool comp(string &s1, string &s2)
    {
        return s1.size()<s2.size();
    }
    int longestStrChain(vector<string>& words) {
        
        sort(words.begin(),words.end(),comp);
        int n=words.size();
        vector<int> dp(n,1);
        int len=0;
        for(int i=0;i<n;i++)
        {
            for(int prev=0;prev<i;prev++)
            {
                if(isCorrect(words[i],words[prev]) and dp[i]<1+dp[prev])
                {
                    dp[i]=1+dp[prev];
                }
            }
            len=max(len,dp[i]);
        }
        return len;
    }
};