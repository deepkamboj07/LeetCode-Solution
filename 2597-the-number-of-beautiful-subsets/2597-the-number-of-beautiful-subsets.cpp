class Solution {
public:

    void solve(vector<int>& nums, int k,unordered_map<int,int> &mp, int &ans, int ind)
    {
        if(ind==nums.size())
        {
            ans++;
            return;
        }
        
        if(!mp[nums[ind]-k] and !mp[nums[ind]+k])
        {
            mp[nums[ind]]++;
            solve(nums,k,mp,ans,ind+1);
            mp[nums[ind]]--;
        }
        solve(nums,k,mp,ans,ind+1);
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int ans=0;
        solve(nums,k,mp,ans,0);
        return ans-1;    
    }
};