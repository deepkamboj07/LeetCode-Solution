class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int n=indices.size();
        string ans="";
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
        {
            v.push_back({indices[i],i});
        }
        
        sort(v.begin(),v.end());
        
        for(int i=0;i<n;i++)
        {
            ans+=s[v[i].second];
        }
        
        return ans;
    }
};