class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> ans;
        int n=s.length();
        vector<int> occu;
        for(int i=0;i<n;i++)
        {
            if(s[i]==c)
                occu.push_back(i);
        }
        
        for(int i=0;i<n;i++)
        {
            int mini=1e9;
            for(int j=0;j<occu.size();j++)
            {
                mini=min(mini, abs(occu[j]-i));
            }
            ans.push_back(mini);
        }
        return ans;
    }
};