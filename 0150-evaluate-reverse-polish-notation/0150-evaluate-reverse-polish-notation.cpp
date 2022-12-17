class Solution {
public:
    
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        
        for(auto s: tokens)
        {
            if(s!="*" and s!="+" and s!="-" and s!="/")
            {
                int dig=stoi(s);
                st.push(dig);
            }
            else
            {
                long long int num1=st.top();st.pop();
                long long int num2=st.top();st.pop();
                long long int ans=0;
                if(s=="*")
                    ans=num1*num2;
                else if(s=="/")
                    ans=num2/num1;
                else if(s=="+")
                    ans=num2+num1;
                else if(s=="-")
                    ans=num2-num1;
                st.push(ans);
            }
        }
        
        return st.top();
    }
};