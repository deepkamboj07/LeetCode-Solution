class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_map<string,int> mp;
        int ans=0;
        for(auto str: words)
        {
            string rev=str;
            reverse(rev.begin(),rev.end());
           // cout<<rev<<endl;
            if(mp.find(rev)!=mp.end())
            {
                ans++;
            }
            
            mp[str]++;
        }
        
        return ans;
    }
};