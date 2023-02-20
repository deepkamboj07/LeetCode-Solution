class Solution {
public:
    bool isValidSerialization(string preorder) {
        
        stack<string> st;
        stringstream s(preorder);
        string str;
        
        while(getline(s, str, ','))
        {

            if(st.empty() || str!="#")
            {
                st.push(str);
            }
            else 
            {
                while(!st.empty() and st.top()=="#")
                {
                    st.pop();
                    if(st.empty())return false;
                    else st.pop();
                }
                st.push(str);
            }
        }
        
        cout<<st.top()<<endl;

        return st.size()==1 and st.top()=="#";
    }
};