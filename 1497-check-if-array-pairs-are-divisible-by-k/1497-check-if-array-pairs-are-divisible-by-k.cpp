class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        
        unordered_map<int,int> mp;
        for(auto num: arr)
        {
            int rem=num%k;
            if(rem<0)rem+=k;
            mp[rem]++;
        }
        
        for(auto it: mp)
        {
            int x=k-it.first;
            if(it.first==0)
            {
                if(it.second%2!=0)return false;
            }
            else
            {
                if(mp[x]==0)return false;
                else
                {
                    int p=it.second;
                    int q=mp[x];
                    
                    if(p!=q)return false;
                }
            }
        }
        
        return true;
    }
};