class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extra) {
        
        int maxi=-1;
        for(auto it: candies)
        {
            maxi=max(maxi,it);
        }
        
        int n=candies.size();
        vector<bool> ans(n,false);

        for(int i=0;i<n;i++)
        {
            if(candies[i] + extra >=maxi)
            {
                ans[i]=true;
            }
        }
        
        return ans;
    }
};