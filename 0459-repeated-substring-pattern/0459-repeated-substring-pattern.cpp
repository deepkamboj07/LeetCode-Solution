class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string str=s+s;
        str=str.substr(1,str.length()-2);
        //cout<<str<<endl;
        if(str.find(s)!=string::npos)return true;
        return false;
    }
};