class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int> pq;
        int n=profits.size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
        {
            v.push_back({capital[i],profits[i]});
        }
        
        sort(v.begin(), v.end());
        int i=0;
        while(k--)
        {
            while(i<n and w>=v[i].first)pq.push(v[i++].second);
            
            if(!pq.empty())
            {
                w+=pq.top();
                pq.pop();
            }
        }
        return w;
    }
};