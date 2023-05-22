class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp; 
        for(int i=0;i<nums.size();i++)
            mp[nums[i]]++;
        priority_queue<pair<int,int>> p;
        
        for(auto i:mp)
            p.push({i.second,i.first});
        
        vector<int> ans;
        
        while(k--)
        {
            ans.push_back(p.top().second);
            p.pop();
        }
        
        return ans;
    }
};