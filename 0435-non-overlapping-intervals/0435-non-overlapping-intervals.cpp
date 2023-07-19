class Solution {
public:

    int eraseOverlapIntervals(vector<vector<int>>& inter) {
        int n=inter.size();
        if(n==0)return 0;
        
        sort(inter.begin(),inter.end());
        int first=inter[0][0];
        int second=inter[0][1];
        int ans=0;
        for(int i=1;i<n;i++)
        {
            if(second <= inter[i][0])
            {
                first=inter[i][0];
                second=inter[i][1];
                continue;
            }
            else if(second <= inter[i][1])
            {
                ans++;
            }
            else if(second > inter[i][1])
            {
                ans++;
                first=inter[i][0];
                second=inter[i][1];
            }
        }
        
        return ans;
        
    }
};