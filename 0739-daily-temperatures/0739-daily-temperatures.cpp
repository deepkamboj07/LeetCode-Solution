class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        vector<int> ans;
        stack<pair<int,int>> st;
        int n=temp.size();
        
        for(int i=n-1;i>=0;i--)
        {
            if(st.empty())
                ans.push_back(0);
            else if(st.top().first >temp[i])
            {
                ans.push_back(st.top().second - i);
            }
            else
            {
                while(!st.empty() and st.top().first <= temp[i])
                {
                    st.pop();
                }
                if(st.empty())ans.push_back(0);
                else ans.push_back(st.top().second - i);
            }
            st.push({temp[i],i});    
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};