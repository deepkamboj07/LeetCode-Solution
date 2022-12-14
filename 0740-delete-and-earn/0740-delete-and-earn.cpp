class Solution {
public:
    
    unordered_map<int,int> count;
    vector<int> dp;
    int solve(int ind,vector<int>&nums)
    {
        if(ind <= 0)return 0;
        
        if(dp[ind]!=-1)return dp[ind];
        
        int take=ind;
        if(count.find(ind)!=count.end())
            take=ind*count[ind];
        else take=0;
        
        if(ind>1)
            take+=solve(ind-2,nums);
        
        int no=solve(ind-1,nums);
        
        return dp[ind]=max(take,no);
           
    }
    int deleteAndEarn(vector<int>& nums) {
        
        for(auto it: nums)
            count[it]++;
        
        vector<int> arr;
        dp=vector(100000,-1);
   
        for(auto it: count)
            arr.push_back(it.first);
        
        sort(arr.begin(), arr.end());
        
        return solve(arr.back(),arr);
    }
};