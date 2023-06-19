class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxi=0;
        int pref=0;
        
        for(auto it: gain)
        {
            pref+=it;
            maxi=max(maxi,pref);
        }
        
        return maxi;
    }
};