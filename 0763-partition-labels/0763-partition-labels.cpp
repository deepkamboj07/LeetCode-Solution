class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> mp;
        int n=s.length();
        
        for(int i=0;i<n;i++)
        {
            mp[s[i]]=i;
        }
        
        int start=0,end=0,j=0;
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            start=i;
            end=mp[s[i]];
            j=i+1;
            while(j<=end)
            {
                if(mp[s[j]] > end)
                {
                    end=mp[s[j]];
                }
                j++;
            }
            
            ans.push_back((end-start+1));
            i=end;
        }
        
        return ans;
    }
};