class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto c: s)
        {
            if(c=='(' or c=='{' or c=='[')
                st.push(c);
            else
            {
                if(st.empty()) return false;
                char ch=st.top();
                if(c==')' and ch=='(') st.pop();
                else if(ch=='{' and c=='}') st.pop();
                else if(ch=='[' and c==']') st.pop();
                else return false;
            }
        }
        return st.empty();
    }
};