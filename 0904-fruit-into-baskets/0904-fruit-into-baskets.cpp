class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> mp;
        int n=fruits.size();
        int i=0,j=0;
        int maxi=-1;
        while(j<n)
        {
            mp[fruits[j]]++;
            while(i<j and mp.size() > 2)
            {
                mp[fruits[i]]--;
                if(mp[fruits[i]]==0)mp.erase(fruits[i]);
                i++;
            }
            j++;
            maxi=max(maxi,(j-i));
        }
        
        return maxi;
    }
};