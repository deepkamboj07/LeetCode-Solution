class Solution {
public:
    int l;
    void solve(vector<int> &nums,vector<vector<int>> &ans,vector<int> &ds,int ind)
    {
        if(ind==nums.size())
        {
            if(ds.size()==l)
                ans.push_back(ds);
            return;
        }
        
        ds.push_back(nums[ind]);
        solve(nums,ans,ds,ind+1);
        ds.pop_back();
        solve(nums,ans,ds,ind+1);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> nums;
        for(int i=1;i<=n;i++)
            nums.push_back(i);
        
        l=k;
        vector<int> ds;
        solve(nums,ans,ds,0);
        return ans;
    }
};