class Solution {
public:
    static bool comp(vector<int>&a, vector<int>&b)
    {
        if(a[0]< b[0])return true;
        if(a[0]==b[0])return a[1]<b[1];
        return false;
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),comp);
        
        stack<pair<int,int>> st;
        for(auto it: points)
        {
            if(st.empty())
            {
                st.push({it[0],it[1]});
            }
            else
            {
                auto top=st.top();
                if(top.first <= it[0] and top.second >= it[0])
                {
                    st.pop();
                    st.push({min(top.first,it[0]), min(top.second, it[1])});
                }
                else st.push({it[0], it[1]});
            }
        }
        
        return (int)st.size();
    }
};