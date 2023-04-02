class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int> res;
        for(auto num:spells)
        {
            long long q=ceil(success/(double)num);
            int ind=lower_bound(potions.begin(), potions.end(), q)- potions.begin();
            int ans=potions.size()-ind;
            res.push_back(ans);
        }
       // cout<<endl;
        return res;
    }
};