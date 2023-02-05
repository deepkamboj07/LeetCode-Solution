class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int k=p.size();
        vector<int> mp(26,0),mp2(26,0);
        for(auto it: p)
            mp[it-'a']++;
        
        int j=0,i=0,n=s.size();
        vector<int> ans;
        while(j<n)
        {
            mp2[s[j]-'a']++;
            if(j-i+1 < k)
            {
                j++;
            }
            else if(j-i+1 == k)
            {
                if(mp2==mp)
                {
                    ans.push_back(i);
                }
                mp2[s[i]-'a']--;
                
                i++;
                j++;
            }
        }
        return ans;
    }
};