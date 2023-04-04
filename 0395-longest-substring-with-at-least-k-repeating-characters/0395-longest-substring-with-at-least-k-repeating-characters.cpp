class Solution {
public:
    int longestSubstring(string s, int k) {
        vector<int> mp(26,0);
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            mp[s[i]-'a']++;
        }
        
        int ind=0;
        while(ind<n and mp[s[ind]-'a']>=k)
            ind++;
        
        if(ind==n)return n;
        
        int left=longestSubstring(s.substr(0,ind),k);
        int right=longestSubstring(s.substr(ind+1),k);
        
        return max(left,right);
    }
};