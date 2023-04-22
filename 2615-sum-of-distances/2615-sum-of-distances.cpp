class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int,vector<int>> mp;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            mp[nums[i]].push_back(i);
        }
        
        vector<long long> ans(n,0);
        for(auto num: mp)
        {
            int n=num.second.size();
            if(n>1)
            {
                vector<int> indc=num.second;
                long long sum=0;
                for(auto i: indc)
                {
                    sum+=i;
                }
                
                long long left=0;
                long long right=sum;
                long long cur=0;
                
                for(int i=0;i<n;i++)
                {
                    cur=0;
                    cur=((long long)i*(long long)indc[i])-(long long)left;
                    cur+=((long long)right-((long long)(n-i)*(long long)indc[i]));
                    left+=indc[i];
                    right-=indc[i];
                    
                    ans[indc[i]]=cur;
                }
            }
        }
        
        return ans;
    }
};