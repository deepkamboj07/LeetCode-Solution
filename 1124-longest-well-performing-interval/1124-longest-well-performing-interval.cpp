class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n=hours.size();
        vector<int> prefix(n,0);
        for(int i=0;i<n;i++)
        {
            if(i==0)
                prefix[i]=(hours[i] > 8)?1:-1;
            else 
                prefix[i]=(hours[i] > 8 ?1:-1 )+ prefix[i-1];
        }
        
        int maxi=0;
        unordered_map<int,int> mp;
        int sum=0;
        for(int i=0;i<n;i++)
        {
           if(hours[i]>8)sum++;
           else sum--;
            
            if(sum > 0)maxi=i+1;
            else
            {
                if(mp.find(sum-1)!=mp.end())
                {
                    maxi=max(maxi,(i-mp[sum-1]));
                }
            }
            
            if(mp.find(sum)==mp.end())
                mp[sum]=i;
        }
        return maxi;
    }
};