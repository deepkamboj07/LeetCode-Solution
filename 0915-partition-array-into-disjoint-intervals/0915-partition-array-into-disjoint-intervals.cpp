class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        priority_queue<int> gre;
        int n=nums.size();
        for(int i=0;i<n;i++)
            pq.push({nums[i],i});
        
        int ans=0,maxi=0;
        int num=nums[0];
        
       for(int i=0;i<n;i++)
       {
           gre.push(nums[i]);
           
           while(!pq.empty() and pq.top().second<=i)pq.pop();
           
           auto top1=gre.top();
           auto top2=pq.top();
           
           if(top2.first >= top1)
           {
               return i+1;
           }
       }
        return -1;
    }
};