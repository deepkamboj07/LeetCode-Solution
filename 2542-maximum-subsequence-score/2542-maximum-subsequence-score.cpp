class Solution {
public:
    static bool comp(pair<int,int>&a, pair<int,int>&b)
    {
        if(a.first==b.first)return a.second > b.second;
        return a.first < b.first;
    }

    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> vec;
        
        int n=nums1.size();
        for(int i=0;i<n;i++)
        {
            vec.push_back({nums2[i], nums1[i]});
        }
        
        sort(vec.begin(), vec.end(), comp);
        long long int ans=0;
        
        int i=0,j=n-1;
        long long int sum=0;
        priority_queue<int,vector<int>, greater<int>> pq;
        
        while(j>=0)
        {
            sum+=vec[j].second;    
            pq.push(vec[j].second);
            if(pq.size()>k)
            {
                sum-=pq.top();
                pq.pop();
            }
            if(pq.size()==k)
            {
                long long int mul=sum*(vec[j].first);
             //   cout<<sum<<"   "<<vec[i].first<<endl;
                ans=max(ans, mul);
            }
            j--;
        }
        
        
        return ans;
    }
};