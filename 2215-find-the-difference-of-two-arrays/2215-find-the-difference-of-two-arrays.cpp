class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_map<int,int> mp,mp2;
        vector<vector<int>> ans;
        for(auto it: nums1)
            mp[it]++;
        for(auto it:nums2){
            mp2[it]++;
        }
        
        vector<int> ds;
        for(auto it:mp)
        {
            if(mp2.find(it.first)==mp2.end())
            {
                ds.push_back(it.first);
            }
        }
        ans.push_back(ds);
        ds.clear();
        for(auto it:mp2)
        {
            //vector<int> ds;
            if(mp.find(it.first)==mp.end())
            {
                ds.push_back(it.first);
            }
        }
        ans.push_back(ds);
        return ans;
    }
};