class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        vector<int> pref,ans;
        pref.push_back(nums[0]);
        
        for(int i=1;i<nums.size();i++)
        {
            pref.push_back(pref.back()+nums[i]);
        }
        
        for(auto num:queries)
        {
            int size=lower_bound(pref.begin(),pref.end(),num)-pref.begin();
            if(size<nums.size() and pref[size]==num) ans.push_back(size+1);
            else ans.push_back(size);
        }    
        return ans;
    }
};