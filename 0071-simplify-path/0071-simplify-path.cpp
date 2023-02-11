class Solution {
public:
    string simplifyPath(string path) {
       string ans="",tmp="";
       stack<string> st;
       for(auto c: path)
        {
            if(isalpha(c) || c=='_' || isdigit(c))
            {
                tmp+=c;
            }
            else if(c=='.')
            {
                tmp+=c;
            }
            else if(!tmp.empty())
            {
                if(tmp==".." and !st.empty())st.pop();
                else if(tmp!=".." and tmp!=".")
                {
                    st.push(tmp);
                }
                tmp="";
            }
        }
        
        if(!tmp.empty())
        {
             if(tmp==".." and !st.empty())st.pop();
                else if(tmp!=".." and tmp!=".")
                {
                    st.push(tmp);
                }
                tmp="";
        }
        
        while(!st.empty())
        {
            ans = "/" + st.top() + ans;
            st.pop();
        }
        
        if(ans.size()==0)return "/";
        return ans;
    }
};