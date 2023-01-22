class Solution {
public:
    bool isPalindrome(string str, int start, int end)
    {
        while(start<=end)
        {
            if(str[start++]!=str[end--])
                return false;
        }
        return true;
    }
    
    void solve(int ind, vector<vector<string>> &ans, string str, vector<string> &ds)
    {
        if(ind==str.size())
        {
            ans.push_back(ds);
            return;
        }
        
        for(int i=ind;i<str.size();++i)
        {
            if(isPalindrome(str,ind,i))
            {
                ds.push_back(str.substr(ind,i-ind+1));
                solve(i+1,ans,str,ds);
                ds.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> ds;
        solve(0,ans,s,ds);
        return ans;
    }
};