class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=s.size();
        int m=t.size();
        if(n>m)return false;
        
        int i=0,j=0;
        while(j<n and i<m)
        {
            if(s[j]==t[i])
            {
                i++;
                j++;
            }
            else i++;
        }
        return j==n;
    }
};