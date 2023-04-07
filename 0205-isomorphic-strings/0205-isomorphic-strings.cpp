class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mp;
        int n=s.length();
        
        for(int i=0;i<n;i++)
        {
            for(auto it: mp)
            {
                if(it.second==t[i] and it.first!=s[i])return false;
            }
            if(mp.find(s[i])!=mp.end())
            {
                s[i]=mp[s[i]];
            }
            else
            {
                mp[s[i]]=t[i];
                s[i]=t[i];
            }
        }
        
        cout<<s<<" "<<t<<endl;
        return s==t;
    }
};