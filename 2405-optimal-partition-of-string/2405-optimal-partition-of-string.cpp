class Solution {
public:
    int partitionString(string s) {
        int n=s.length();
        vector<int> mp(26,0);
        int count=1;
        for(int i=0;i<n;i++)
        {
            int ch=s[i]-'a';
           // cout<<ch<<" ";
            if(mp[ch]==0)
            {
                mp[ch]++;
            }
            else
            {
                count++;
                mp=vector<int>(26,0);
                mp[ch]++;
            }
        }
        
        return count;
    }
};