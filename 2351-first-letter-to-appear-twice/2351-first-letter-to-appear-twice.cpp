class Solution {
public:
    char repeatedCharacter(string s) {
        vector<int> mp(26,0);
        for(auto ch: s)
        {
            if(mp[ch-'a']==0)mp[ch-'a']++;
            else return ch;
        }
        return 'j';
    }
};