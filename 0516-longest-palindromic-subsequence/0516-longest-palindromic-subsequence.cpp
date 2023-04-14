class Solution {
public:
    int lcs(string s1,string s2)
    {
        int n=s1.size();
        int m=s2.size();
        
        vector<int> prev(m+1,0);
        for(int i=1;i<=n;i++)
        {
            vector<int> cur(m+1,0);
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1])cur[j]=1+prev[j-1];
                else cur[j]=max(prev[j],cur[j-1]);
            }
            prev=cur;
        }
        return prev[m];
    }
    int longestPalindromeSubseq(string s) {
        string s2=s;
        reverse(s.begin(),s.end());
        
        return lcs(s2,s);
    }
};