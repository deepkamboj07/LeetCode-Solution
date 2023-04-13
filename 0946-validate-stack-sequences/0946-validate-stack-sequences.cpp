class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        
        int n=pushed.size();
        int j=0,i=0;
        while(i<n)
        {
            while(!st.empty() and j<n and st.top()==popped[j])
            {
                st.pop();
                j++;
            }
            
            if(i<n)
            {
                st.push(pushed[i]);
                i++;
            }
        }
        
        while(!st.empty() and j<n)
        {
            if(popped[j]==st.top())st.pop();
            else break;
            
            j++;
        }
        
        return st.empty();
    }
};