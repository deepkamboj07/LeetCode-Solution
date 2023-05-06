class Solution {
public:
    int longestContinuousSubstring(string s) {
        int n=s.length();
        int i=0,j=0,maxi=1;
        int c=0;
        for(i=0;i<n-1;i++)
        {
            if((s[i]-'0')+1 == s[i+1]-'0')
            {
                c++;
            }
            else
            {
                maxi=max(maxi,c+1);
                c=0;
            }
        }
        
        maxi=max(maxi,c+1);
        return maxi;
    }
};