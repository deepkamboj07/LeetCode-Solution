class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> mp;
        for(auto it: arr1)
            mp[it]++;
        
        vector<int> ans;
        for(auto n: arr2)
        {
            int freq=mp[n];
            while(freq--)
            {
                ans.push_back(n);
            }
            mp.erase(n);
        }
        
        for(auto it: mp)
        {
            int freq=mp[it.first];
            while(freq--)
            {
                ans.push_back(it.first);
            }
        }
        
        return ans;
    }
};