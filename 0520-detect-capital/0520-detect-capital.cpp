class Solution {
public:
    bool detectCapitalUse(string word) {
        
        int upper=0, lower=0;
        for(auto ch: word)
        {
            if(isupper(ch))
            {
                upper++;
                if(lower!=0)return false;
            }
            else lower++;
        }
        
        if(upper==word.length() || lower==word.length() || 1+lower==word.length())return true;
        return false;
    }
};