class Solution {
public:
    int strStr(string haystack, string p) {
        if(p.length()==0)return 0;
        
        int it=haystack.find(p);
        if(it==string::npos)return -1;
        
        return it;
    }
};