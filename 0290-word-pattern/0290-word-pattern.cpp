class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> mp;
        int n=pattern.length(),i=0,j=0;
        int m=s.length();
        char c;
        unordered_set<string> st; 
        string tmp="";
        while(i<n and j<m)
        {
            c=pattern[i];
            tmp="";
            while(j<m and s[j]!=' ')
            {
                tmp+=s[j];
                j++;
            }
            
            if(mp.find(c)==mp.end() and st.find(tmp)==st.end())
            {
                mp[c]=tmp;       
                st.insert(tmp);
            }
            else if(mp[c]!=tmp)return false;
            i++;
            j++;
        }
        
        if(mp.find(c)==mp.end() and st.find(tmp)!=st.end())
        {
            mp[c]=tmp;
        }
        else if(mp[c]!=tmp)return false;
        
        if(i<n || j<m)return false;
        
        return true;
    }
};