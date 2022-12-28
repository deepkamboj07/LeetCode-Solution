class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        for(auto it: piles)
            pq.push(it);
        
        while(!pq.empty() and k>0)
        {
            int top=pq.top();
            pq.pop();
            int ans=ceil(top/2.0);
            k--;
            pq.push(ans);
        }
        
        int ans=0;
        while(!pq.empty())
        {
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};