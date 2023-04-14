class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char,int> mp;
        for(auto ch: allowed)
        {
            mp[ch]=1;
        }
        
        int count=0;
        for(auto str: words)
        {
            bool flag=true;
            for(auto ch: str)
            {
                if(mp[ch]==0)flag=false;
            }
            if(flag)count++;
        }
        
        return count;
    }
};