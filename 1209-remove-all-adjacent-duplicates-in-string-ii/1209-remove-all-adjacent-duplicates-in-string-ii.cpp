class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        
        for(auto ch: s)
        {
            if(!st.empty() and st.top().first==ch)
            {
                auto top=st.top();
                st.pop();
                if(top.second<(k-1))
                {
                    int count=top.second;
                    st.push({ch,(count+1)});
                }
            }
            else
            {
                st.push({ch,1});
            }
        }
        
        string ans="";
        while(!st.empty())
        {
            int count=st.top().second;
            while(count--)
            {
                ans+=st.top().first;
            }
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};