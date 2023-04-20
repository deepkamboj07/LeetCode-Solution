class Solution {
public:

    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        
        vector<pair<int,int>> vc;
        unordered_map<int,int> mp,mp2;
        int n=values.size();
        for(int i=0;i<n;i++)
        {
            vc.push_back({values[i],labels[i]});
            mp[labels[i]]++;
        }
        
        sort(vc.rbegin(), vc.rend());
        int ans=0;
        
        for(int i=0;i<n and numWanted>0;i++)
        {
            if(mp2[vc[i].second] < useLimit)
            {
                ans+=vc[i].first;
                mp2[vc[i].second]++;
                numWanted--;
            }
        }
        
        return ans;
    }
};