class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        vector<pair<bool,int>> mp(26,{false,-1});
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            char ch=s[i];
            int ind=ch-'a';
            if(mp[ind].second==-1)
            {
                mp[ind].first=true;
                mp[ind].second=i;
            }
            else
            {
                mp[ind].second=(i-mp[ind].second)-1;
            }
        }
        
        for(int i=0;i<26;i++)
        {
            if(mp[i].first==true)
            {
                if(mp[i].second != distance[i])return false;
            }
        }
        return true;
    }
};