class Solution {
public:
    bool buddyStrings(string s, string goal) {
        
        int n=s.size();
        int m=goal.size();
        if(n!=m)return false;
        
        int c1=-1,c2=-1;
        unordered_set<int> st;
        
        for(int i=0;i<n;i++)
        {
            if(s[i]!=goal[i])
            {
                if(c1==-1)
                    c1=i;
                else if(c2==-1)
                    c2=i;
                else return false;
            }
            st.insert(s[i]);
        }
        
        if(c1!=-1 and c2!=-1)
        {
            return s[c1]==goal[c2] and s[c2]==goal[c1];
        }
       
        if(c1!=-1)return false;
        
        return st.size()<s.size();
    }
};