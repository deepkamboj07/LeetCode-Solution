class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        queue<int> q;
        unordered_set<string> st;
        unordered_set<int> vis;
        for(auto s:wordDict)
            st.insert(s);
        
        q.push(0);
        while(!q.empty())
        {
            int start=q.front();
            q.pop();
            
            if(vis.find(start)==vis.end())
            {
                vis.insert(start);
                for(int i=start;i<s.size();i++)
                {
                    string tmp(s,start,i-start+1);
                  //  cout<<tmp<<" ";
                    if(st.find(tmp)!=st.end())
                    {
                       // cout<<"\n"<<tmp<<endl;
                        q.push(i+1);
                        if(i+1==s.size())return true;
                    }
                }
            }
        }
        return false;
    }
};