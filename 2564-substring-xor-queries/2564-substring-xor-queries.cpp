class Solution {
public:
    int binaryToDecimal(string n, unordered_map<int,pair<int,int>> &mp)
    {
        string num = n;
        int dec_value = 0;
        long long int base = 1;

        int len = num.length();
        int j=n.size()-1;
        int s=n.size()-1;
        int count=0;
        for (int i = len - 1; i >= 0 && count<=31; i--) {
            if (num[i] == '1')
                dec_value += base;
            if(mp.find(dec_value)==mp.end())
            {
                mp[dec_value].first=j;
                mp[dec_value].second=s;
            }
            count++;
            j--;
            base = base * 2;
        }

        return dec_value;
    }
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        unordered_map<int,pair<int,int>> mp;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
           string tmp=s.substr(0,i+1);
           int digit=binaryToDecimal(tmp,mp);
        }
        
        vector<vector<int>> ans;
        for(auto q: queries)
        {
            int x=q[0]^q[1];
            if(mp.find(x)!=mp.end())
            {
                ans.push_back({mp[x].first,mp[x].second});
            }
            else ans.push_back({-1,-1});
        }
//         for(auto it: mp)
//         {
//             cout<<it.first<<"  -  "<<it.second.first<<","<<it.second.second<<endl;
//         }
        
        return ans;
    }
};