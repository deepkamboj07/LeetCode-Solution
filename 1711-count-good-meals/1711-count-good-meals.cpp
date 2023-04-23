class Solution {
public:
    int mod=1e9+7;
    int countPairs(vector<int>& deliciousness) {
        vector<long long> set;
        for(int i=0;i<22;i++)
        {
            set.push_back(pow(2,i));
        }
        
        unordered_map<int,long long int> mp;
        long long int ans=0;
        
        for(auto num: deliciousness)
        {
            for(auto p: set)
            {
                int power=p-num;
                ans=(ans%mod + mp[power]%mod)%mod;
            }
            mp[num]++;
        }
        return ans;
    }
};