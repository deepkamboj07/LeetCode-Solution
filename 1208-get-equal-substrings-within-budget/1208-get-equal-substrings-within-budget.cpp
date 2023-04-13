class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int i=0,j=0;
        int n=s.length();
        
        int sum=0;
        int maxi=0;
        while(j<n)
        {
            sum+=abs(s[j]-t[j]);
            if(sum <= maxCost)
            {
                maxi=max(maxi,j-i+1);
                j++;
            }
            else
            {
                while(i<j and sum>maxCost)
                {
                    sum-=abs(s[i]-t[i]);
                    i++;
                }
                if(sum <= maxCost)maxi=max(maxi,j-i+1);
                j++;
            }
        }
        return maxi;
        
    }
};