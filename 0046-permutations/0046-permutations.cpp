class Solution {
public:
    set<vector<int>> set;
    void solve(int ind,vector<int>&nums, vector<int>&ds)
    {
        if(ind==nums.size())
        {
            set.insert(nums);         
            return;
        }
        
        for(int i=ind;i<nums.size();i++)
        {
            swap(nums[i],nums[ind]);
            solve(ind+1,nums,ds);
            swap(nums[i],nums[ind]);     
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> ds;
        solve(0,nums,ds);
        //cout<<set.size();
        vector<vector<int>> ans(set.begin(), set.end());
        return ans;
    }
};