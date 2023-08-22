class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans="";
        while(columnNumber)
        {
            columnNumber--;
            int mod=columnNumber%26;
            ans+=mod+'A';
            columnNumber/=26;
        }
       reverse(ans.begin(), ans.end());
        return ans;
    }
};