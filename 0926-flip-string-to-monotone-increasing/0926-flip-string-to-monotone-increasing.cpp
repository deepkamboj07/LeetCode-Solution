class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int one=0;
        int mini=0;
        for(auto ch: s)
        {
            if(ch=='1')one++;
            else
            {
                mini++;
                mini=min(mini,one);
            }
        }
        return mini;
    }
};