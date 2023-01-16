class Solution {
public:
    void mergeInt(vector<vector<int>> &ans)
    {
        stack<pair<int,int>> st;
        for(auto it:ans)
        {
            if(st.empty())
                st.push({it[0],it[1]});
            else
            {
                auto top=st.top();
                if(it[0] >= top.first and it[0]<= top.second)
                {
                    st.pop();
                    st.push({min(it[0],top.first), max(it[1],top.second)});
                }
                else
                {
                    st.push({it[0],it[1]});
                }
            }
        }
        
        ans.clear();
        while(!st.empty())
        {
            ans.push_back({st.top().first , st.top().second});
            st.pop();
        }
        reverse(ans.begin(),ans.end());
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        
        int n=intervals.size();
        if(n==0)
            return {newInterval};
        
        int i=0,j=0;
        while(i<n)
        {
            int num1=intervals[i][0];
            int num2=newInterval[0];
            
            if(num1<num2)
            {
                ans.push_back(intervals[i]);
            }
            else
            {
                ans.push_back({num2,newInterval[1]});
                break;
            }
            i++;
        }
        
        
        if(i==n)
            ans.push_back(newInterval);
        
        while(i<n)
        {
            ans.push_back(intervals[i++]);
        }
        
        mergeInt(ans);
       
        return ans;
        
    }
};